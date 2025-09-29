/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:28:56 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/04 13:45:17 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors

Character::Character() : _name("CJ") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 10; i++)
		this->_trash[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 10; i++)
		this->_trash[i] = NULL;
}


Character::Character(const Character &other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 10; i++) {
        this->_trash[i] = NULL;
    }
}

// Operador de asignación (copia profunda)
Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;

		// Limpiar lo que ya tengo
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i]) {
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}

		// Copiar other Character
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		// Limpiar basura anterior
        for (int i = 0; i < 10; i++) {
            if (_trash[i]) {
                delete _trash[i];
                _trash[i] = NULL;
            }
        }
	}
	return *this;
}

// Destructor
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (this->_trash[i]){
			delete this->_trash[i];
			this->_trash[i] = NULL;
		}
	}
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::manage_leftover(int idx)
{
	delete this->_trash[9];
	this->_trash[9] = this->_inventory[idx];
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
        return;

    for (int i = 0; i < 10; i++)
    {
        if (!this->_trash[i])
        {
            this->_trash[i] = this->_inventory[idx];
            this->_inventory[idx] = NULL;
            return ;
        }
    }
    manage_leftover(idx);
    this->_inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
		return ;

	this->_inventory[idx]->use(target);
}
