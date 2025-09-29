/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:44 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/30 07:50:24 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;
	
	std::cout << std::endl;
	const Animal *animals[10];

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

	Cat* cat = (Cat*)animals[0]; // cast sin comprobación
	cat->setIdea(0, "I want food");
	std::cout << "Idea: " << cat->getIdea(0) << std::endl;
	std::cout << std::endl;

	for (int i=0; i < 10; i++) {
		delete animals[i];
	}

	return 0;
}