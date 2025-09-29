/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:40:44 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 13:10:29 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	const WrongAnimal* animal = new WrongCat();
    animal->makeSound();
    
	// Al no tener destructor en virtual, no se destruye la clase derivaba, por lo que
	// hay una destrucción incompleta, si la clase WrongCat reserbara memoria dinámica
	// y se dejará así aquí habría un leak.
	delete animal;

	return 0;
}