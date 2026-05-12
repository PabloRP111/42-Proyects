/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:25 by femoreno          #+#    #+#             */
/*   Updated: 2025/12/17 13:45:35 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <vector>
#include <cstdlib>

#include "aux1.hpp"

// Forward declarations
struct Server;
struct Client;
struct Channel;

void handle_JOIN(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_PRIVMSG(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_NOTICE(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_QUIT(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_PART(Server &server, Client *c, const std::vector<std::string> &tokens);

