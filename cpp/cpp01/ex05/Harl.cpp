/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:37:35 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 08:26:09 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string toLower(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::tolower(str[i]);
    return str;
}

Harl::Harl(){}
Harl::~Harl(){}

void	Harl::debug() {
	std::cout << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO] - I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING] - I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR] - This is unacceptable ! I want to speak to the manager now." << std::endl;;
}

void	Harl::complain(std::string level) {
	void			(Harl::*arrayPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		arrayLevel[4] = {"debug", "info", "warning", "error"};
	int				i = 0;

	while (i < 4 && arrayLevel[i] != toLower(level))
		i++;
	if (i == 4) {
		std::cout << "This level doesn't exist" << std::endl;
		return;
	}
	(this->*arrayPtr[i])();
}
