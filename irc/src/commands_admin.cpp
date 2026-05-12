#include "commands_admin.hpp"

bool user_in_channel(Server &server, Client *c, Channel *channel)
{
	std::set<Client*>::iterator iter = channel->members.find(c);
	if (iter != channel->members.end())
		return true;
	send_to_client(c,
		":server 442 " + c->nickname + " " + channel->name + " :You're not on that channel\r\n",
		server.fds);
	return false;
}

Client *target_in_channel(Server &server, Client *c, Channel *channel, const std::string &target)
{
	for (std::set<Client*>::iterator it = channel->members.begin(); it != channel->members.end(); ++it)
	{
		if ((*it)->nickname == target)
		{
			return (*it);
		}
	}
	send_to_client(c,
		":server 441 " + c->nickname + " " + target + " " + channel->name + " :They aren't on that channel\r\n",
		server.fds);
	return NULL;
}

void topic_to_all(Server &server, Channel *channel)
{
	for (std::set<Client*>::iterator it = channel->members.begin(); it != channel->members.end(); ++it)
	{
		if (channel->topic.empty())
			send_to_client(*it,
				":server 331 " + (*it)->nickname + " " + channel->name + " :No topic is set\r\n",
				server.fds);
		else
			send_to_client(*it,
				":server 332 " + (*it)->nickname + " " + channel->name + " :" + channel->topic + "\r\n",
				server.fds);
	}
}

void handle_KICK(Server &server, Client *c, const std::vector<std::string> &tokens)
{
	if (tokens.size() < 3)
	{
		send_to_client(c,
            ":server 461 " + c->nickname + " KICK :Not enough parameters\r\n",
            server.fds);
        return;
	}
	const std::string &channel_name = tokens[1];
	const std::string &target = tokens[2];
	std::map<std::string, Channel*>::iterator iter = server.channels.find(channel_name);
	//channel exists
	if (iter != server.channels.end())
	{
		Channel *channel = iter->second;
		if (!user_in_channel(server, c, channel))
			return;
		//user is op
		if (channel->operators.find(c) != channel->operators.end())
		{
			//try to find target user
			Client *to_kick = target_in_channel(server, c, channel, target);
			//target is not in channel
			if (!to_kick)
				return;
			else
			{
				//:<nick>!<user>@<host> KICK #channel <nick> :<reason>
				std::string response;
				if (tokens.size() > 3)
				{
					std::string reason;
					for (size_t i = 3; i < tokens.size(); i++)
					{
						reason += tokens[i];
						if (i + 1 <= tokens.size())
							reason += " ";
					}
					response = ":" + c->nickname + "!" + c->username + "@localhost KICK " + channel->name + " " + to_kick->nickname + " :" + reason + "\r\n";
				}
				else
					response = ":" + c->nickname + "!" + c->username + "@localhost KICK " + channel->name + " " + to_kick->nickname + " :No reason provided" + "\r\n";
				send_to_all_clients(channel, response, server);
				channel->operators.erase(to_kick);
				channel->members.erase(to_kick);
				to_kick->channels.erase(channel->name);
				if (channel->members.empty())
				{
					channel->operators.clear();
					delete channel;
					server.channels.erase(iter);// Si no queda nadie en el canal, eliminarlo
					//continue;
				}
				if (channel->operators.empty() && !channel->members.empty())
				{
					Client *new_op = *channel->members.begin();
					channel->operators.insert(new_op); // Si no hay mas operadores, asignar uno nuevo
					send_to_all_clients(channel,
							":" + server.hostname +
							" MODE " + channel->name +
							" +o " + new_op->nickname + "\r\n"
							, server);
				}
				return;
			}
		}
		//user is not op
		else
		{
			send_to_client(c,
				":server 482 " + c->nickname + " " + channel->name + " :You're not channel operator\r\n",
				server.fds);
			return;
		}
	}
	//channel doesn't exist
	else
	{
		send_to_client(c,
			":server 403 " + c->nickname + " " + tokens[1] + " :No such channel\r\n",
			server.fds);
		return;
	}
}

void handle_TOPIC(Server &server, Client *c, const std::vector<std::string> &tokens)
{
	if (tokens.size() < 2)
	{
		send_to_client(c,
            ":server 461 " + c->nickname + " TOPIC :Not enough parameters\r\n",
            server.fds);
        return;
	}
	const std::string &channel_name = tokens[1];
	std::map<std::string, Channel*>::iterator iter = server.channels.find(channel_name);
	//channel exists
	if (iter != server.channels.end())
	{
		Channel *channel = iter->second;
		if (!user_in_channel(server, c, channel))
			return;
		//user is not op and channel is set to mode t
		if (channel->mode_t && channel->operators.find(c) == channel->operators.end())
		{
			send_to_client(c,
				":server 482 " + c->nickname + " " + channel->name + " :You're not channel operator\r\n",
				server.fds);
			return;
		}
		else
		{
			if (tokens.size() == 2)
			{
				topic_to_all(server, channel);
				// :<server> 331 <nick> #channel :No topic is set
			}
			else
			{
                std::string topic;
                for (size_t i = 2; i < tokens.size(); i++)
                {
    				topic += tokens[i];
                    if (i + 1 <= tokens.size())
                        topic += " ";
                }
				channel->topic = topic;
				topic_to_all(server, channel);
			}
			return;
		}
	}
	//channel doesn't exist
	else
	{
		send_to_client(c,
			":server 403 " + c->nickname + " " + tokens[1] + " :No such channel\r\n",
			server.fds);
		return;
	}
}

void handle_INVITE(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
    {
        send_to_client(c,
            ":server 461 " + c->nickname + " INVITE :Not enough parameters\r\n",
            server.fds);
        return;
    }

    const std::string &target_nick = tokens[1];
    const std::string &channel_name = tokens[2];
    // buscar usuario a invitar
    Client *to_invite = NULL;
    for (std::map<int, Client*>::iterator it = server.clients.begin();
         it != server.clients.end(); ++it)
    {
        if (it->second->nickname == target_nick)
        {
            to_invite = it->second;
            break;
        }
    }

    if (!to_invite)
    {
        send_to_client(c,
            ":server 401 " + c->nickname + " " + target_nick +
            " :No such nick/channel\r\n",
            server.fds);
        return;
    }

    // buscar canal
    std::map<std::string, Channel*>::iterator it = server.channels.find(channel_name);
    if (it == server.channels.end())
    {
        send_to_client(c,
            ":server 403 " + c->nickname + " " + channel_name +
            " :No such channel\r\n",
            server.fds);
        return;
    }

    Channel *channel = it->second;
    if (!user_in_channel(server, c, channel))
        return;

    // canal +i → solo operadores
    if (channel->mode_i && channel->operators.find(c) == channel->operators.end())
    {
        send_to_client(c,
            ":server 482 " + c->nickname + " " + channel_name +
            " :You're not channel operator\r\n",
            server.fds);
        return;
    }

    // ya está en el canal
    if (channel->members.find(to_invite) != channel->members.end())
    {
        send_to_client(c,
            ":server 443 " + c->nickname + " " + target_nick +
            " " + channel_name + " :is already on channel\r\n",
            server.fds);
        return;
    }

	if (channel->guests.find(to_invite) == channel->guests.end())
		channel->guests.insert(to_invite);

    // RPL_INVITING al emisor
    send_to_client(c,
        ":server 341 " + c->nickname + " " + target_nick +
        " " + channel_name + "\r\n",
        server.fds);

    // INVITE al usuario invitado
    send_to_client(to_invite,
        ":" + c->nickname + "!" + c->username +
        "@localhost INVITE " + target_nick +
        " :" + channel_name + "\r\n",
        server.fds);
}


void handle_MODE(Server &server, Client *c, const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        send_to_client(c,
            ":server 461 " + c->nickname + " MODE :Not enough parameters\r\n",
            server.fds);
        return;
    }

    const std::string &channel_name = tokens[1];
    std::map<std::string, Channel*>::iterator it = server.channels.find(channel_name);
    if (it == server.channels.end())
    {
        send_to_client(c,
            ":server 403 " + c->nickname + " " + channel_name + " :No such channel\r\n",
            server.fds);
        return;
    }

    Channel *channel = it->second;
    if (!user_in_channel(server, c, channel))
        return;

    if (tokens.size() == 2)
    {
        std::string modes = "+";
        std::string params;

        if (channel->mode_i)
			modes += "i";
        if (channel->mode_t)
			modes += "t";

        if (!channel->key.empty())
        {
            modes += "k";
            params += " " + channel->key;
        }

        if (channel->limit >= 0)
        {
            modes += "l";
            std::stringstream ss;
            ss << channel->limit;
            params += " " + ss.str();
        }

        if (modes == "+")
            modes.clear();
        else
            modes = " " + modes;

        send_to_client(c,
            ":server 324 " + c->nickname + " " + channel->name + modes + params + "\r\n",
            server.fds);
        return;
    }

    if (channel->operators.find(c) == channel->operators.end())
    {
        send_to_client(c,
            ":server 482 " + c->nickname + " " + channel->name +
            " :You're not channel operator\r\n",
            server.fds);
        return;
    }

    const std::string &flag = tokens[2];
    if (flag.size() < 2 || (flag[0] != '+' && flag[0] != '-'))
    {
        send_to_client(c,
            ":server 472 " + c->nickname + " * :is unknown mode char to me\r\n",
            server.fds);
        return;
    }

    char sign = flag[0];
    char mode = flag[1];
    std::string param;
    if (((mode == 'k' || mode == 'l') && sign == '+') || mode == 'o')
    {
        if (tokens.size() < 4)
        {
            send_to_client(c,
                ":server 461 " + c->nickname + " MODE :Not enough parameters\r\n",
                server.fds);
            return;
        }
        param = tokens[3];
    }

    Client *target = NULL;
    switch (mode)
    {
        case 'i':
            channel->mode_i = (sign == '+');
            break;

        case 't':
            channel->mode_t = (sign == '+');
            break;

        case 'k':
            if (sign == '+')
                channel->key = param;
            else
                channel->key.clear();
            break;

        case 'l':
            if (sign == '+')
                channel->limit = std::atoi(param.c_str());
            else
                channel->limit = -1;
            break;

        case 'o':
            target = target_in_channel(server, c, channel, param);
            if (!target)
                return;
            if (sign == '+')
            {
                if (channel->operators.find(target) != channel->operators.end())
                    return;
                channel->operators.insert(target);
            }
            else if (sign == '-')
                channel->operators.erase(target);
            break;

        default:
            send_to_client(c,
                ":server 472 " + c->nickname + " " + mode +
                " :is unknown mode char to me\r\n",
                server.fds);
            return;
    }

    std::string msg = ":" + c->nickname + "!" + c->username +
        "@localhost MODE " + channel->name + " " + flag;

    if (!param.empty())
        msg += " " + param;

    msg += "\r\n";

    send_to_all_clients(channel, msg, server);
}
