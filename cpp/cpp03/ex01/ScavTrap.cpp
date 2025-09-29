/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:57:05 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/24 13:52:13 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " created with default constructor!" << std::endl;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other._name)
{
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
	_hitPts = other._hitPts;

	std::cout << "ScavTrap " << _name << " created with copy constructor!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other); // Esto es igual a _name = other._name;, pero mejor
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPts > 0)
	{
		if (this->_hitPts <= 0)
		{
			std::cout << "ScavTrap " << _name << " is dead and cannot attack " << target << "!" << std::endl;
			return ;
		}
		std::cout << "ScavTrap " << _name << " attacks to " << target << ", causing "
			<< _attackDmg << " points of damage!" << std::endl;
		_energyPts--;	
	} else
		std::cout << "ScavTrap " << _name << " doesn't have enough energy to attack "
			<< target << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
