/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:00:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 09:50:31 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::srand(std::time(NULL));

	Bureaucrat	bureaucratBender("Bender", 1);
	Bureaucrat	bureaucratFry("Fry", 145);
	AForm		*FRobot = new RobotomyRequestForm();
	AForm		*FPresidencial = new PresidentialPardonForm();
	AForm		*FShruberry = new ShrubberyCreationForm();
	
	std::cout << *FRobot << std::endl << std::endl;
	std::cout << *FPresidencial << std::endl << std::endl;
	std::cout << *FShruberry << std::endl << std::endl;

	try {
		bureaucratFry.signForm(*FPresidencial);
	} catch (const std::exception& e) {
       std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	try {
		bureaucratBender.signForm(*FRobot);
		FRobot->execute(bureaucratFry);
	} catch (const std::exception& e) {
       std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	try {
		bureaucratBender.signForm(*FRobot);
		bureaucratBender.signForm(*FShruberry);
		bureaucratBender.signForm(*FPresidencial);
		std::cout << std::endl;
		
		FRobot->execute(bureaucratBender);
		std::cout << std::endl;
		FPresidencial->execute(bureaucratBender);
		std::cout << std::endl;
		FShruberry->execute(bureaucratBender);
	} catch (const std::exception& e) {
       std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	
	delete FRobot;
	delete FPresidencial;
	delete FShruberry;
}
