/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:00:33 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 12:54:48 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors && Destructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal created with default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) 
{
	_type = other._type;
	std::cout << "WrongAnimal created with copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other); //asigna la variable del constructor principal
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destroyed" << std::endl;
}

// Methods of Class
void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal noise" << std::endl;
}
		
// Getters && Setters
std::string	WrongAnimal::getType(){
	return _type;
}

void	WrongAnimal::setType(std::string type) {
	_type = type;
}
