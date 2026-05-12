/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:29 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/18 14:06:03 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

volatile sig_atomic_t g_running = 1;

void handle_term(int)
{
    g_running = 0;
}

void	dispatch_line(Server &server, Client *c, const std::string &line)
{
	if (line.empty())
		return;

	std::vector<std::string> tokens = split_irc(line);
	if (tokens.empty())
		return;
	
	std::string cmd = to_upper(tokens[0]);

	if (!c->registered)
    {
        if (cmd != "PASS" && cmd != "NICK" && cmd != "USER" && cmd != "CAP")
        {
            send_to_client(c, ":server 451 * :You have not registered\r\n", server.fds);
            return;
        }
    }

	if (cmd == "NICK")
        handle_NICK(server, c, tokens);
    else if (cmd == "USER")
        handle_USER(server, c, tokens);
	else if (cmd == "PASS")
        handle_PASS(server, c, tokens);
    else if (cmd == "JOIN")
        handle_JOIN(server, c, tokens);
	else if (cmd == "PING")
        handle_PING(server, c, tokens);
	else if (cmd == "KICK")
        handle_KICK(server, c, tokens);
    else if (cmd == "INVITE")
        handle_INVITE(server, c, tokens);
    else if (cmd == "TOPIC")
        handle_TOPIC(server, c, tokens);
    else if (cmd == "MODE")
        handle_MODE(server, c, tokens);
    else if (cmd == "PRIVMSG")
        handle_PRIVMSG(server, c, tokens);
	else if (cmd == "NOTICE")
        handle_NOTICE(server, c, tokens);
	else if (cmd == "WHO")
        handle_WHO(server, c, tokens);
	else if (cmd == "LIST")
        handle_LIST(server, c, tokens);
	else if (cmd == "CAP")
	    handle_CAP(server, c, tokens);
	else if (cmd == "QUIT")
		handle_QUIT(server, c, tokens);
	else if (cmd == "PART")
	    handle_PART(server, c, tokens);
    else
        send_to_client(c, ":server 421 " + cmd + " :Unknown command\r\n", server.fds);
}

void extract_lines_and_dispatch(Server &server, Client* c)
{
    std::string &s = c->read_buf;
    size_t pos;
    while (true)
	{
        // find CRLF, CR = '\r', LF = '\n'
        pos = s.find("\r\n");
        if (pos == std::string::npos) // std::string::npos = not found
			pos = s.find('\n');
        if (pos == std::string::npos)
			break;

        std::string line = s.substr(0, pos);
        // si encontramos "\r\n limpiamos la r
        if (!line.empty() && line[line.size()-1] == '\r')
			line.erase(line.size()-1);

		// delete '\r' && || '\n'
        s.erase(0, pos + ((s[pos]=='\r' && pos+1 < s.size() && s[pos+1]=='\n') ? 2 : 1));
        dispatch_line(server, c, line);
    }
}

int main(int argc, char *argv[])
{
	signal(SIGPIPE, SIG_IGN);
	signal(SIGTSTP, SIG_IGN); //CtrlZ
    signal(SIGTERM, handle_term); //kill
    signal(SIGINT, handle_term); //CtrlC

	if (argc != 3)
    {
        std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }

	int port = std::atoi(argv[1]);
    std::string password = argv[2];
    Server server(port, password);

	int server_fd = socket(AF_INET, SOCK_STREAM, 0); //Create a socket for the server
	if (server_fd < 0)
		throw std::runtime_error("socket failed");

	int enable = 1;
	//Config socket options
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

	sockaddr_in addr;
	addr.sin_family = AF_INET; //Set IPv4
	addr.sin_port = htons(server.port); //Transform port int into network-byte-order
	addr.sin_addr.s_addr = INADDR_ANY; //Allow connections from any interface

	if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) //Associate socket to this port and ip
	{
		perror("bind");
		close(server_fd);
		return 1;
	}

	if (listen(server_fd, SOMAXCONN) < 0) // Puts socket in server mode
		throw std::runtime_error("listen failed");

	pollfd serverPoll;
	serverPoll.fd = server_fd; //Indicate who serverPoll is watching
	serverPoll.events = POLLIN; //Notifies you when someone enters
	serverPoll.revents = 0;
	server.fds.push_back(serverPoll);

	while (g_running)
	{
		int activity = poll(server.fds.data(), server.fds.size(), -1); // -1 block without timeout
		if (activity < 0)//poll failed
		{
			if (errno == EINTR)
				continue;
			perror("poll");
			break;
		}

		// Check if there is a new connection
		if (server.fds[0].revents & POLLIN)
		{
			sockaddr_in cli_addr;
			socklen_t len = sizeof(cli_addr);
			int client_fd = accept(server_fd, (sockaddr*)&cli_addr, &len);
			if (client_fd < 0)
				continue;

			// Poner el cliente en modo no bloqueante
			fcntl(client_fd, F_SETFL, O_NONBLOCK); //fcntl(server_fd, F_SETFL, O_NONBLOCK);

			pollfd clientPoll;
			clientPoll.fd = client_fd;
			clientPoll.events = POLLIN;
			clientPoll.revents = 0;
			// Add client socket to the poll
			server.fds.push_back(clientPoll);

			// Registrer the client in the server structure
			server.clients[client_fd] = new Client(client_fd);
			std::cout << "Nuevo cliente conectado: " << client_fd << "\n";
			send_to_client(server.clients[client_fd],
			":server NOTICE * :Please register using PASS <password>, NICK <nick> and USER <user> 0 * :<realname>\r\n",
			server.fds);
		}
		// Manage custom activities
		for (size_t i = 1; i < server.fds.size(); ++i)
		{
			// The client gone or his socket is in bad state
			if (server.fds[i].revents & (POLLHUP | POLLERR))
			{
				std::cout << "Cliente desconectado: " << server.fds[i].fd << "\n";
				close_and_remove_client(server, i);
				i--;
				continue;
			}
			if (server.fds[i].revents & POLLIN)
			{
				int fd = server.fds[i].fd;
				std::map<int, Client*>::iterator it = server.clients.find(fd);
				if (it == server.clients.end())
					continue;

				Client *c = it->second;
				char buf[4096];
				while (true)
				{
					ssize_t n = recv(c->fd, buf, sizeof(buf), 0);
					if (n > 0)
					{
						c->read_buf.append(buf, buf + n);
						if (c->read_buf.size() > 8192)
						{
							// kill client for flood
							close_and_remove_client(server, i);
							i--;
							break;
						}
						extract_lines_and_dispatch(server, c);
						if (c->should_close)
						{
							close_and_remove_client(server, i);
							i--;
							break;
						}
					}
					else if(n == 0)
					{
						close_and_remove_client(server, i);
						i--;
						break;
					}
					else
					{
						if (errno == EAGAIN || errno == EWOULDBLOCK) //There is non data
							break;
						//Error
						close_and_remove_client(server, i);
						i--;
						break;
					}
				}
			}
			if (server.fds[i].revents & POLLOUT)
			{
				Client* c = server.clients[server.fds[i].fd];
				while (!c->write_buf.empty())
				{
					ssize_t n = send(c->fd, c->write_buf.c_str(), c->write_buf.size(), 0); //real send
					if (n > 0)
						c->write_buf.erase(0, n);
					else
					{
						if (errno == EAGAIN || errno == EWOULDBLOCK)
							break;
						close_and_remove_client(server, i);
						i--;
						break;
					}
				}
				if (c->write_buf.empty())
					server.fds[i].events &= ~POLLOUT; //quit POLLOUT
			}
			// clean revents to avoid contamination in the next pool
			server.fds[i].revents = 0;
		}
	}
	free_server(server);
}
