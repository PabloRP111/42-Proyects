/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:22 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 12:16:55 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors && Destructor
Cat::Cat() : Animal(){
	_type = "Cat";
	std::cout << "Cat created with default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(){
	_type = other._type;
	std::cout << "Cat created with copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destroyed" << std::endl;
}

// Methods of Class
void Cat::makeSound() const
{
	std::cout << "Meow jjjjjjjjjjjj" << std::endl;
}
