/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:21 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/19 13:26:47 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.hpp"
#include "main.hpp"

// JOIN
void handle_JOIN(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        send_to_client(c, 
            ":" + server.hostname + " 461 " + c->nickname + " JOIN :Not enough parameters\r\n", 
            server.fds);
        return;
    }

    const std::string& channel_name = tokens[1];

    // validate channel name
    if (!is_valid_channel_name(channel_name))
    {
        send_to_client(c,
            ":" + server.hostname + " 403 " + c->nickname + " " + channel_name + " :Invalid channel name\r\n",
            server.fds);
        return;
    }

    Channel *chan = NULL;
    
    // create channel if doesnt exist
    if (server.channels.find(channel_name) == server.channels.end())
    {
        chan = new Channel(channel_name);
        server.channels[channel_name] = chan;
        chan->operators.insert(c);
    }
    else
    {
        chan = server.channels[channel_name];
        if (chan->mode_i && ((chan->guests.find(c) == chan->guests.end())))
        {
            send_to_client(c,
                ":" + server.hostname + " 473 " + c->nickname + " " + channel_name + " :Cannot join channel (+i)\r\n",
                server.fds);
            return;
        }
        if (chan->limit != -1 && static_cast<int>(chan->members.size()) >= chan->limit)
        {
            send_to_client(c,
                ":" + server.hostname + " 471 " + c->nickname + " " + channel_name + " :Cannot join channel (+l)\r\n",
                server.fds);
            return;
        }
        if (!chan->key.empty())
        {
            if (tokens.size() < 3 || tokens[2] != chan->key)
            {
                send_to_client(c,
                    ":" + server.hostname + " 475 " + c->nickname + " " + channel_name + " :Cannot join channel (+k)\r\n",
                    server.fds);
                return;
            }
        }
    }
    
    chan->members.insert(c);
    c->channels.insert(channel_name);
    chan->guests.erase(c);

    // send JOIN
    for (std::set<Client*>::iterator it = chan->members.begin(); it != chan->members.end(); ++it)
    {
        send_to_client(*it,
            ":" + c->nickname + "!" + c->username + "@localhost JOIN :" + channel_name + "\r\n",
            server.fds);
    }

    // send topic
    if (!chan->topic.empty())
    {
        send_to_client(c,
            ":" + server.hostname + " 332 " + c->nickname + " " + channel_name + " :" + chan->topic + "\r\n",
            server.fds);
    }

    // built name list
    std::string names;
    for (std::set<Client*>::iterator it = chan->members.begin(); it != chan->members.end(); ++it)
    {
        if (chan->operators.find(*it) != chan->operators.end())
            names += "@" + (*it)->nickname + " ";
        else
            names += (*it)->nickname + " ";
    }

    // RPL_NAMREPLY
    char chanel_type;
    if (chan->mode_i)
        chanel_type = '*';
    else
        chanel_type = '=';
    send_to_client(c,
        ":" + server.hostname + " 353 " + c->nickname + " " + chanel_type + " " + channel_name + " :" + names + "\r\n",
        server.fds);

    // RPL_ENDOFNAMES
    send_to_client(c,
        ":" + server.hostname + " 366 " + c->nickname + " " + channel_name + " :End of NAMES list\r\n",
        server.fds);
}

void handle_NOTICE(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
        return;

    std::vector<std::string> targets = split(tokens[1], ',');
    std::string message;
    for (size_t i = 2; i < tokens.size(); i++)
    {
        message += tokens[i];
        if (i + 1 < tokens.size())
            message += " ";
    }
    if (!message.empty() && message[0] == ':')
        message.erase(0,1);
    if (message.empty())
        return;

   for (size_t i = 0; i < targets.size(); i++)
    {
        // Check if target is a channel
        if (targets[i][0] == '#')
        {
            if (server.channels.find(targets[i]) != server.channels.end())
            {
                //Check if sender is member of the channel
                std::set<std::string>::iterator it = c->channels.find(targets[i]);
                if (it == c->channels.end())
                    continue ;

                Channel *chan = server.channels[targets[i]];
                // Send message to all members in the channel
                for (std::set<Client*>::iterator it = chan->members.begin(); it != chan->members.end(); ++it)
                {
                    Client *member = *it;
                    if (member != c)
                    {
                        send_to_client(member,
                            ":" + c->nickname + "!" + c->username + "@localhost NOTICE " + targets[i] + " :" + message + "\r\n",
                            server.fds);
                    }
                }
            }
        }
        else
        {
            // Target is not a channel, check if it's a user
            bool user_found = false;
            for (std::map<int, Client*>::iterator it = server.clients.begin(); it != server.clients.end(); ++it)
            {
                Client *client = it->second;
                if (client->nickname == targets[i])
                {
                    user_found = true;
                    send_to_client(client,
                        ":" + c->nickname + "!" + c->username + "@localhost NOTICE " + targets[i] + " :" + message + "\r\n",
                        server.fds);
                    break;
                }
            }
        }
    }
}

// PRIVMSG
void handle_PRIVMSG(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
    {
        send_to_client(c,
            ":" + server.hostname + " 461 " + c->nickname + " PRIVMSG :Not enough parameters\r\n",
            server.fds);
        return;
    }

    std::vector<std::string> targets = split(tokens[1], ',');
    std::string message;
    for (size_t i = 2; i < tokens.size(); i++)
    {
        message += tokens[i];
        if (i + 1 < tokens.size())
            message += " ";
    }
    if (!message.empty() && message[0] == ':')
        message.erase(0,1);
    if (message.empty())
    {
        send_to_client(c,
            ":" + server.hostname + " 412 " + c->nickname + " :No text to send\r\n",
            server.fds);
        return;
    }

   for (size_t i = 0; i < targets.size(); i++)
    {
        // Check if target is a channel
        if (targets[i][0] == '#')
        {
            if (server.channels.find(targets[i]) != server.channels.end())
            {
                //Check if sender is member of the channel
                std::set<std::string>::iterator it = c->channels.find(targets[i]);
                if (it == c->channels.end())
                {
                    send_to_client(c,
                        ":" + server.hostname + " 442 " + c->nickname + " " + targets[i] + " :You're not on that channel\r\n",
                        server.fds);
                    continue ;
                }

                Channel *chan = server.channels[targets[i]];
                // Send message to all members in the channel
                for (std::set<Client*>::iterator it = chan->members.begin(); it != chan->members.end(); ++it)
                {
                    Client *member = *it;
                    if (member != c)
                    {
                        send_to_client(member,
                            ":" + c->nickname + "!" + c->username + "@localhost PRIVMSG " + targets[i] + " :" + message + "\r\n",
                            server.fds);
                    }
                }
            }
            else
            {
                send_to_client(c,
                    ":" + server.hostname + " 403 " + c->nickname + " " + targets[i] + " :No such channel\r\n",
                    server.fds);
            }
        }
        else
        {
            // Target is not a channel, check if it's a user
            bool user_found = false;
            for (std::map<int, Client*>::iterator it = server.clients.begin(); it != server.clients.end(); ++it)
            {
                Client *client = it->second;
                if (client->nickname == targets[i])
                {
                    user_found = true;
                    send_to_client(client,
                        ":" + c->nickname + "!" + c->username + "@localhost PRIVMSG " + targets[i] + " :" + message + "\r\n",
                        server.fds);
                    break;
                }
            }
            if (!user_found)
            {
                send_to_client(c,
                    ":" + server.hostname + " 401 " + c->nickname + " " + targets[i] + " :No such nick/channel\r\n",
                    server.fds);
            }
        }
    }
}

void handle_PART(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        send_to_client(c, ":" + server.hostname + " 461 " + c->nickname + " PART :Not enough parameters\r\n", server.fds);
        return;
    }

    std::vector<std::string> targets = split(tokens[1], ',');
    std::string message;
    for (size_t i = 2; i < tokens.size(); ++i)
    {
        message += tokens[i];
        if (i + 1 < tokens.size())
            message += " ";
    }
    if (!message.empty() && message[0] == ':')
        message.erase(0,1);

    std::vector<std::string> empty_channels;

    for (size_t t = 0; t < targets.size(); ++t)
    {
        std::string chan_name = targets[t];
        std::map<std::string, Channel*>::iterator ch_it = server.channels.find(chan_name);
        if (ch_it == server.channels.end())
        {
            send_to_client(c, ":" + server.hostname + " 403 " + c->nickname + " " + chan_name + " :No such channel\r\n", server.fds);
            continue;
        }

        Channel *chan = ch_it->second;

        if (c->channels.find(chan_name) == c->channels.end())
        {
            send_to_client(c, ":" + server.hostname + " 442 " + c->nickname + " " + chan_name + " :You're not on that channel\r\n", server.fds);
            continue;
        }

        // Copia de miembros para enviar mensajes
        std::set<Client*> members_copy = chan->members;
        for (std::set<Client*>::iterator it = members_copy.begin(); it != members_copy.end(); ++it)
        {
            Client* member = *it;
            if (!message.empty())
                send_to_client(member, ":" + c->nickname + "!" + c->username + "@localhost PART " + chan_name + " :" + message + "\r\n", server.fds);
            else
                send_to_client(member, ":" + c->nickname + "!" + c->username + "@localhost PART " + chan_name + "\r\n", server.fds);
        }

        // Eliminar cliente del canal
        chan->members.erase(c);
        chan->operators.erase(c);
        c->channels.erase(chan_name);

        if (chan->members.empty())
            empty_channels.push_back(chan_name);
        else if (chan->operators.empty())
        {
            Client* new_op = *(chan->members.begin());
            chan->operators.insert(new_op);
            send_to_all_clients(chan, ":" + server.hostname + " MODE " + chan->name + " +o " + new_op->nickname + "\r\n", server);
        }
    }

    // Borrar canales vacíos
    for (size_t i = 0; i < empty_channels.size(); ++i)
    {
        std::string chan_name = empty_channels[i];
        delete server.channels[chan_name];
        server.channels.erase(chan_name);
    }
}

void handle_QUIT(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    std::string reason = "Client Quit";
    if (tokens.size() > 1)
    {
        reason = tokens[1][0] == ':' ? tokens[1].substr(1) : tokens[1];
        for (size_t i = 2; i < tokens.size(); ++i)
            reason += " " + tokens[i];
    }

    std::string quit_msg = ":" + c->nickname + "!" + c->username + "@localhost QUIT :" + reason + "\r\n";

    // Copia de los canales para iterar de forma segura
    std::vector<std::string> channels_copy;
    for (std::set<std::string>::iterator it = c->channels.begin(); it != c->channels.end(); ++it)
        channels_copy.push_back(*it);

    std::vector<std::string> empty_channels;

    for (size_t i = 0; i < channels_copy.size(); ++i)
    {
        std::string chan_name = channels_copy[i];
        std::map<std::string, Channel*>::iterator ch_it = server.channels.find(chan_name);
        if (ch_it == server.channels.end())
            continue;

        Channel *ch = ch_it->second;

        // Copia de miembros para enviar mensajes
        std::set<Client*> members_copy = ch->members;
        members_copy.erase(c);
        for (std::set<Client*>::iterator mem_it = members_copy.begin(); mem_it != members_copy.end(); ++mem_it)
            send_to_client(*mem_it, quit_msg, server.fds);

        // Eliminar al cliente
        ch->members.erase(c);
        ch->operators.erase(c);

        if (ch->members.empty())
            empty_channels.push_back(chan_name);
        else if (ch->operators.empty())
        {
            Client *new_op = *(ch->members.begin());
            ch->operators.insert(new_op);
            send_to_all_clients(ch, ":" + server.hostname + " MODE " + ch->name + " +o " + new_op->nickname + "\r\n", server);
        }
    }

    // Borrar canales vacíos
    for (size_t i = 0; i < empty_channels.size(); ++i)
    {
        std::string chan_name = empty_channels[i];
        delete server.channels[chan_name];
        server.channels.erase(chan_name);
    }

    c->channels.clear();
    c->should_close = true;
}
