#pragma once

#include "main.hpp"
#include <sstream>

struct Server;
struct Client;

bool user_in_channel(Server &server, Client *c, Channel *channel);
void handle_KICK(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_INVITE(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_TOPIC(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_MODE(Server &server, Client *c, const std::vector<std::string> &tokens);