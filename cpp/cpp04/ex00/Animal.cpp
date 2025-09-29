/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:04 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 12:54:06 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors && Destructor
Animal::Animal() : _type("Animal"){
	std::cout << "Animal created with default constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	_type = other._type;
	std::cout << "Animal created with copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other) {
		Animal::operator=(other); //asigna la variable del constructor principal
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destroyed" << std::endl;
}

// Methods of Class
void Animal::makeSound() const{
	std::cout << "Animal noise" << std::endl;
}
		
// Getters && Setters
std::string	Animal::getType() const{
	return _type;
}

void	Animal::setType(std::string type) {
	_type = type;
}
