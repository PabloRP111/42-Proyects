/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:03:48 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/24 09:50:23 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Setters
void	ClapTrap::setName(std::string name){_name = name;}

void	ClapTrap::setAttackDmg(unsigned int amount){_attackDmg = amount;}

void	ClapTrap::setHitPts(unsigned int amount){_hitPts = amount;}

void	ClapTrap::setEnergyPts(unsigned int amount){_energyPts = amount;}

// Getters
std::string	ClapTrap::getName()
{
	return _name;
}

unsigned int	ClapTrap::getAttackDmg()
{
	return _attackDmg;
}

unsigned int	ClapTrap::getEnergyPts()
{
	return _energyPts;
}

unsigned int	ClapTrap::getHitPts()
{
	return _hitPts;
}

// Constructors
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0) {
	std::cout << "ClapTrap " << _name << " created with default constructor!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	_name = other._name;
	_hitPts = other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;

	std::cout << "ClapTrap " << _name << " created with compare constructor!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other)
	{
        _name = other._name;
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
	}
	return *this;
}

// Methods 
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPts > 0)
    {
        if (amount >= _hitPts)
        {
            _hitPts = 0;
            std::cout << "ClapTrap " << _name << " has dead!" << std::endl;
        }
        else
        {
            _hitPts -= amount;
            std::cout << "ClapTrap " << _name << " takes " << amount 
                      << " points of damage, now has " << _hitPts << " hit points!" << std::endl;
        }
    }
    else
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPts > 0)
	{
		if (this->_hitPts <= 0)
		{
			std::cout << "ClapTrap " << _name << " it´s dead, can´t repairs itself" << std::endl;
			return ;
		}
		_hitPts += amount;
		std::cout << "ClapTrap " << _name << " repairs itself, it regains "
			<< amount << " hit points. Now it has " << _hitPts << " of life." << std::endl;
		_energyPts--;	
	}
	else
		std::cout << "ClapTrap " << _name << " don´t have enought energy to repair it selves!"
			<< std::endl;
}

void	ClapTrap::attack(const std::string	&target)
{
	if (this->_energyPts > 0)
	{
		if (this->_hitPts <= 0)
		{
			std::cout << "ClapTrap " << _name << " it´s dead, can´t  attacks to " << target  << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << _name << " attacks to " << target << ", causing "
			<< _attackDmg << " points of damage!" << std::endl;
		_energyPts--;	
	} else
		std::cout << "ClapTrap " << _name << " don´t have enought energy to attacks "
			<< target << std::endl;

}
