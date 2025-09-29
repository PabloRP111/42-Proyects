/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:01:11 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 12:54:38 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors && Destructor
WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	std::cout << "WrongCat created with default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(){
	_type = other._type;
	std::cout << "WrongCat created with copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destroyed" << std::endl;
}

// Methods of Class
void WrongCat::makeSound() const{
	std::cout << "Wrong Meow jjjjjjjjjjjj" << std::endl;
}
