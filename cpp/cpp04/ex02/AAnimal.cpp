/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:04 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/30 08:45:23 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors && Destructor
AAnimal::AAnimal() : _type("AAnimal"){
	std::cout << "AAnimal created with default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	_type = other._type;
	std::cout << "AAnimal created with copy constructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other) {
		AAnimal::operator=(other); //asigna la variable del constructor principal
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destroyed" << std::endl;
}

// Methods of Class
void AAnimal::makeSound() const{
	std::cout << "AAnimal noise" << std::endl;
}
		
// Getters && Setters
std::string	AAnimal::getType() const{
	return _type;
}

void	AAnimal::setType(std::string type) {
	_type = type;
}
