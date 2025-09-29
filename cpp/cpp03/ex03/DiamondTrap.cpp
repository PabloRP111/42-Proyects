/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:03:45 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 09:53:03 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	_hitPts = FragTrap::_hitPts;
	_energyPts = ScavTrap::_energyPts;
	_attackDmg = FragTrap::_attackDmg;

	std::cout << "DiamondTrap " << _name << " created with default constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " created with copy constructor!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other); //asigna la variable del constructor principal, en este caso _name
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
