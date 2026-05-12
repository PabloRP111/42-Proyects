
#pragma once
#include <string>
#include <vector>

#include "aux.hpp"

// Forward declarations
struct Server;
struct Client;
struct Channel;

void handle_NICK(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_USER(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_PING(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_PASS(Server &s, Client *c, const std::vector<std::string> &tokens);
void handle_CAP(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_WHO(Server &server, Client *c, const std::vector<std::string> &tokens);
void handle_LIST(Server &server, Client *c, std::vector<std::string> &tokens);
