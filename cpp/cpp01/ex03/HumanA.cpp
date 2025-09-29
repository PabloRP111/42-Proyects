/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:46:11 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/17 17:27:49 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_wp): name(_name), wp(_wp){}
HumanA::~HumanA(){}

std::string HumanA::getName() const{
	return name;
}

void	HumanA::setName(std::string new_name)
{
	name = new_name;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}
