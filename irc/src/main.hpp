/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:33 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/12 11:21:43 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <poll.h>           // poll(), pollfd y las flags POLLIN, POLLOUT, etc.
#include <sys/socket.h>     // socket, bind, listen, accept
#include <netinet/in.h>     // sockaddr_in
#include <arpa/inet.h>      // htons, inet_*, IP conversions
#include <unistd.h>         // close
#include <cstring> 			// memset
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fcntl.h>
#include <cerrno>
#include <cstdio>
#include <signal.h>
#include "aux1.hpp"
#include "commands.hpp"
#include "commands_admin.hpp"
#include "passive_commands.hpp"

#define CLIENT_TIMEOUT 300

struct Client
{
	int fd;
	std::string nickname;
    std::string username;
	std::string realname;
	std::string hostname;
	std::string read_buf;
	std::string write_buf;
	std::set<std::string> channels;
	bool has_nickname;
	bool has_username;
	bool pass_ok;
	bool registered;
	bool should_close;
	Client(int fd_socket) :  fd(fd_socket), hostname("localhost"), has_nickname(false),
		has_username(false), pass_ok(false), registered(false),	should_close(false) {}
};

struct Channel
{
	std::string name;
	std::string topic;
	std::set<Client*> members;
	std::set<Client*> operators;
	std::set<Client*> guests;
	bool mode_i;
	bool mode_t;
	std::string key;
	int limit;

	Channel(const std::string& n) : name(n),
		topic(""), mode_i(false), mode_t(false),
        key(""), limit(-1) {}
};

struct Server
{
	int port;
	std::string password;
	std::string hostname;
	std::map<std::string, Channel*> channels;
	std::map<int, Client*> clients;
	std::vector<pollfd> fds;

	Server(int p, std::string pass) : port(p), password(pass),
		hostname("ircServer") {}
};
