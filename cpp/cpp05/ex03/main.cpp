/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:00:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 12:38:10 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main()
{
	std::srand(std::time(NULL));

	Bureaucrat	bureaucratBender("Bender", 1);
	Bureaucrat	bureaucratFry("Fry", 145);
	Intern		intern;

	AForm		*FRobot;
	AForm		*FPresidencial;
	AForm		*FShruberry;
	AForm		*prueba;

	try {
		FRobot = intern.makeForm("robotomy request", "Pablo");
		FPresidencial = intern.makeForm("presidential request", "Pablo");
		FShruberry = intern.makeForm("shruberry request", "Pablo");
		prueba = intern.makeForm("random request", "Pablo");
	} catch (const std::exception& e) {
       std::cerr << "Exception catched: " << e.what() << std::endl;
    }

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
