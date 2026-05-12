#include "passive_commands.hpp"
#include "main.hpp"

//PASS
void handle_PASS(Server &s, Client *c, const std::vector<std::string> &tokens)
{
    if (c->registered)
    {
        send_to_client(c,
            ":server 462 " + c->nickname + " :You may not reregister\r\n",
            s.fds);
        return;
    }

    if (tokens.size() < 2)
    {
        send_to_client(c,
            ":server 461 * PASS :Not enough parameters\r\n",
            s.fds);
        return;
    }

    if (tokens[1] != s.password)
    {
        send_to_client(c,
            ":server 464 * :Password incorrect\r\n",
            s.fds);

        c->should_close = true;
        return;
    }

    c->pass_ok = true;
}

// CAP
void handle_CAP(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
        return;

    if (tokens[1] == "LS")
    {
        send_to_client(c, ":server CAP * LS :\r\n", server.fds);
    }
    else if (tokens[1] == "END")
    {
        if (c->has_username && c->has_nickname && !c->registered && c->pass_ok)
            register_client(server, c);
    }
}

// NICK
void handle_NICK(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
        return;

    if (!c->has_nickname)
        c->has_nickname = true;

    if (!is_valid_nick(tokens[1]))
    {
        send_to_client(c, ":server 432 * " + tokens[1] + " :Erroneous nickname\r\n", server.fds);
        return;
    }

    std::map<int, Client*>::iterator it;
    for (it = server.clients.begin(); it != server.clients.end(); ++it)
    {
        if (it->second->nickname == tokens[1])
        {
            send_to_client(c,
                ":server 433 * " + tokens[1] + " :Nickname is already in use\r\n",
                server.fds);
            return;
        }
    }

    c->nickname = tokens[1];
    if (c->has_username && c->has_nickname && !c->registered && c->pass_ok)
        register_client(server, c);
}

// USER
void handle_USER(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 5)
        return;

    if (c->has_username)
    {
        send_to_client(c,
            ":server 462 " + c->nickname + " :You may not reregister\r\n",
            server.fds);
        return;
    }

    c->username = tokens[1];
    c->has_username = true;

    // realname
    std::string realname;
    for (size_t i = 4; i < tokens.size(); ++i)
    {
        realname += tokens[i];
        if (i + 1 < tokens.size())
            realname += " ";
    }

    if (!realname.empty() && realname[0] == ':')
        realname.erase(0, 1);

    c->realname = realname;

    if (c->has_username && c->has_nickname && !c->registered && c->pass_ok)
        register_client(server, c);
}


void handle_PING(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
        return;

    std::string response = "PONG :" + tokens[1] + "\r\n";
    send_to_client(c, response, server.fds);
}

void handle_WHO(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    std::string mask = tokens.size() > 1 ? tokens[1] : "*";

    // WHO #canal
    if (!mask.empty() && mask[0] == '#')
    {
        std::map<std::string, Channel*>::iterator it = server.channels.find(mask);
        if (it == server.channels.end())
        {
            send_to_client(c,
                ":" + server.hostname + " 315 " + c->nickname + " " + mask +
                " :End of WHO list\r\n",
                server.fds);
            return;
        }

        Channel *ch = it->second;

        for (std::set<Client*>::iterator iter = ch->members.begin();
             iter != ch->members.end(); ++iter)
        {
            Client *member = *iter;

            bool is_op = ch->operators.find(member) != ch->operators.end();

            std::string flags = "H";
            std::string nick = member->nickname;

            if (is_op)
                nick = "@" + nick;

            send_to_client(c,
                ":" + server.hostname + " 352 " + c->nickname + " " + ch->name +
                " " + member->username +
                " " + member->hostname +
                " " + server.hostname +
                " " + nick +
                " " + flags +
                " :0 " + member->realname + "\r\n",
                server.fds);
        }

        send_to_client(c,
            ":" + server.hostname + " 315 " + c->nickname + " " + mask +
            " :End of WHO list\r\n",
            server.fds);
        return;
    }

    // WHO nick (mínimo)
    for (std::map<int, Client*>::iterator it = server.clients.begin();
         it != server.clients.end(); ++it)
    {
        Client *target = it->second;
        if (target->nickname == mask)
        {
            send_to_client(c,
                ":" + server.hostname + " 352 " + c->nickname + " * " +
                target->username +
                " " + target->hostname +
                " " + server.hostname +
                " " + target->nickname +
                " H :0 " + target->realname + "\r\n",
                server.fds);
            break;
        }
    }

    send_to_client(c,
        ":" + server.hostname + " 315 " + c->nickname + " " + mask +
        " :End of WHO list\r\n",
        server.fds);
}

void    handle_LIST(Server &server, Client *c, std::vector<std::string> &tokens)
{
    if (tokens.size() != 1)
        return;

    for (std::map<std::string, Channel*>::iterator it = server.channels.begin(); it != server.channels.end(); it++)
    {
        Channel *ch = it->second;
        std::ostringstream oss;
        oss << ch->members.size();
        send_to_client(c, server.hostname + " 322 " + c->nickname + " " + ch->name + " " +
        oss.str() + " :" + ch->topic + "\r\n",
        server.fds);
    }
    send_to_client(c, server.hostname + " 323 " + c->nickname + " :End of LIST" + "\r\n", server.fds);
}
