/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:00:49 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/14 08:07:30 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	int r = std::rand() % 3;
	std::cout << "" << std::endl;
    switch (r) {
        case 0:
			std::cout << "Debug: type is A" << std::endl;
			return new A();
        case 1:
			std::cout << "Debug: type is B" << std::endl;
			return new B();
        default:
			std::cout << "Debug: type is C" << std::endl;
			return new C();
    }
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It´s a A object!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It´s a B object!" << std::endl;
	else
		std::cout << "It´s a C object!" << std::endl;
}

void	identify(Base &p)
{
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "It´s a A object!" << std::endl;
	else if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "It´s a B object!" << std::endl;
	else
		std::cout << "It´s a C object!" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	Base *b = generate();
	identify(b);
	identify(*b);
	delete(b);

	Base *b2 = generate();
	identify(b2);
	identify(*b2);
	delete(b2);
}