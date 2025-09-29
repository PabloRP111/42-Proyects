/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:29 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 12:40:46 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors && Destructor
Dog::Dog() : Animal(){
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog created with default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(){
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog created with copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = other._brain;
	}
	return *this;
}

Dog::~Dog(){
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
}

// Methods of Class
void Dog::makeSound() const
{
	std::cout << "Wouf grrrrrrr" << std::endl;
}

//Setters y Getters
void Dog::setIdea (int index, const std::string &idea) {
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}
