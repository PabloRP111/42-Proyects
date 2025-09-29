/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:56:26 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 08:45:40 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " created with default constructor!" << std::endl;
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other._name)
{
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
	_hitPts = other._hitPts;

	std::cout << "FragTrap " << _name << " created with copy constructor!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requests high fives from everyone! ✋" << std::endl;
}

