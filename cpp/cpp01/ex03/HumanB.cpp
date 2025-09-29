/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:46:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/17 17:27:57 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name){}
HumanB::~HumanB(){}

std::string HumanB::getName() const {
	return name;
}

void	HumanB::setName(std::string new_name) {
	name = new_name;
}

void	HumanB::setWeapon(Weapon &_wp) //Simbolo para ref
{
	wp = &_wp; //Simbolo para address
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << wp->getType() << std::endl;
}
