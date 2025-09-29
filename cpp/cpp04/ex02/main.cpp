/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:44 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/30 08:50:36 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal *animals[10];

	for (int i=0; i < 10; i++) {
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << std::endl;
	
	for (int i=0; i < 10; i++) {
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	//const AAnimal animal = new AAnimal(); //No esta permitido al ser Abstracta la clase 

	for (int i=0; i < 10; i++) {
		delete animals[i];
	}
	return 0;
}