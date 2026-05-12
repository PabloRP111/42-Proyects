/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:09 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/12 12:07:56 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>         // close
#include <vector>
#include <string>
#include <poll.h>

// Forward declarations
struct Server;
struct Client;
struct Channel;

void						send_welcome(Server &server, Client *c);
void    					free_server(Server &server);
void						close_and_remove_client(Server &server, size_t index);
void    					close_client(Server &server, int fd);
void						send_to_client(Client *c, const std::string &msg, std::vector<pollfd> &fds);
void						send_to_all_clients(Channel *channel, std::string response, Server &server);
void 						register_client(Server &server, Client *c);
std::vector<std::string>	split_irc(const std::string &line);
std::vector<std::string>	split(const std::string &s, char delim);
std::string					to_upper(std::string s);
bool						is_valid_channel_name(const std::string& name);
bool						is_valid_nick(const std::string& nick);
