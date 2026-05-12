/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:00 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/12 12:05:08 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.hpp"
#include "main.hpp"

void send_to_all_clients(Channel *channel, std::string response, Server &server)
{
	for (std::set<Client*>::iterator it = channel->members.begin(); it != channel->members.end(); ++it)
	{
		send_to_client(*it, response, server.fds);
	}
}

bool is_valid_nick(const std::string& nick)
{
    if (nick.empty())
        return false;

    // El primer carácter debe ser letra o símbolo especial
    // Permitamos A–Z, a–z, y los símbolos especiales [ ] \ ` _ ^
    char c = nick[0];
    if (!std::isalpha(c) && c != '[' && c != ']' && c != '\\'
        && c != '`' && c != '_' && c != '^')
    {
        return false;
    }

    // El resto pueden ser letras, dígitos o - _ [ ] \ ` ^
    for (size_t i = 1; i < nick.size(); ++i)
    {
        char ch = nick[i];

        if (!std::isalnum(ch) &&
            ch != '-' && ch != '_' &&
            ch != '[' && ch != ']' &&
            ch != '\\' && ch != '`' &&
            ch != '^')
        {
            return false;
        }
    }

    return true;
}

void    close_and_remove_client(Server &server, size_t index)
{
    int fd = server.fds[index].fd;
    close(fd);
    delete server.clients[fd];
    server.clients.erase(fd);

    server.fds.erase(server.fds.begin() + index);
}

void    close_client(Server &server, int fd)
{
    close(fd);
    delete server.clients[fd];
    server.clients.erase(fd);
    for (int i = 0; i < static_cast<int>(server.fds.size()); ++i)
    {
        if (server.fds[i].fd == fd)
        {
            server.fds.erase(server.fds.begin() + i);
            break;
        }
    }
}

void    free_server(Server &server)
{
    for (std::map<int, Client*>::iterator it = server.clients.begin();
         it != server.clients.end(); )
    {
        Client* c = it->second;
        if (c)
        {
            close(c->fd);
            delete c;
        }
        std::map<int, Client*>::iterator it_delete = it;  
        it++;
        server.clients.erase(it_delete);
    }

    for (std::map<std::string, Channel*>::iterator it = server.channels.begin();
         it != server.channels.end(); )
    {
        Channel* ch = it->second;
        delete ch;
        std::map<std::string, Channel*>::iterator it_delete = it;
        it++;
        server.channels.erase(it_delete);
    }

    server.fds.clear();
}

void register_client(Server &server, Client *c)
{
    std::cout << "Registrando cliente: nickname='" << c->nickname << "', username='" << c->username << "'\n";
    c->registered = true;
    send_welcome(server, c);
}

void send_to_client(Client *c, const std::string &msg, std::vector<pollfd> &fds)
{
    c->write_buf += msg;
    for (size_t i = 1; i < fds.size(); ++i)
    {
        if (fds[i].fd == c->fd)
        {
            fds[i].events |= POLLOUT;
            break;
        }
    }
}

void send_welcome(Server &server, Client *c)
{
    std::string nick = c->nickname;
    std::string server_name = server.hostname;

    send_to_client(c,
        ":" + server_name + " 001 " + nick +
        " :Welcome to the IRC network, " + nick + "\r\n",
        server.fds);

    send_to_client(c,
        ":" + server_name + " 002 " + nick +
        " :Your host is " + server_name + "\r\n",
        server.fds);

    send_to_client(c,
        ":" + server_name + " 003 " + nick +
        " :This server was created today\r\n",
        server.fds);

    send_to_client(c,
        ":" + server_name + " 004 " + nick +
        " " + server_name + " 1.0 iwo itkl\r\n",
        server.fds);

    send_to_client(c,
        ":" + server_name + " 005 " + nick +
        " CHANTYPES=# :are supported by this server\r\n",
        server.fds);
}

bool is_valid_channel_name(const std::string& name)
{
    if (name.size() < 2)
        return false;
    if (name[0] != '#')
        return false;

    for (size_t i = 1; i < name.size(); i++)
    {
        char c = name[i];
        if (c <= 32 || c == ',' )
            return false;
    }
    return true;
}

std::vector<std::string> split_irc(const std::string &line)
{
    std::vector<std::string> out;
    size_t i = 0;

    while (i < line.size())
    {
        while (i < line.size() && line[i] == ' ')
            i++;
        if (i >= line.size())
            break;

        // final token
        if (line[i] == ':') {
            out.push_back(line.substr(i + 1));
            break;
        }

        // normal token
        size_t start = i;
        while (i < line.size() && line[i] != ' ')
            i++;
        out.push_back(line.substr(start, i - start));
    }
    return out;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> result;
    std::string current;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == delim)
        {
            if (!current.empty())
                result.push_back(current);
            current.clear();
        }
        else
            current += s[i];
    }

    if (!current.empty())
        result.push_back(current);

    return result;
}

std::string to_upper(std::string s)
{
    for (size_t i = 0; i < s.size(); ++i)
        s[i] = std::toupper(s[i]);
    return s;
}
