/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:29 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 12:17:00 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors && Destructor
Dog::Dog() : Animal(){
	_type = "Dog";
	std::cout << "Dog created with default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(){
	_type = other._type;
	std::cout << "Dog created with copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destroyed" << std::endl;
}

// Methods of Class
void Dog::makeSound() const
{
	std::cout << "Wouf grrrrrrr" << std::endl;
}
