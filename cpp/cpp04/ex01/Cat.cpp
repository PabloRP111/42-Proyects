/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:22 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 12:40:48 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors && Destructor
Cat::Cat() : Animal(){
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat created with default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(){
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Cat created with copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = other._brain;
	}
	return *this;
}

Cat::~Cat(){
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
}

// Methods of Class
void Cat::makeSound() const
{
	std::cout << "Meow jjjjjjjjjjjj" << std::endl;
}

//Setters y Getters
void Cat::setIdea(int index, const std::string &idea) {
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}
