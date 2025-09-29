/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:00:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 09:20:01 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	bureaucrat("Pablo", 2);
	Form		form1;
	Form		form2("Top Secret MKUltra", false, 1, 1);

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl << std::endl;

	try {
		Form	form3("Out of bounds Form", false, 151, 151);
	} catch (const std::exception& e) {
        std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	bureaucrat.signForm(form1);
	std::cout << std::endl;

	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form2);
	bureaucrat.increaseGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form2);
	std::cout << form2 << std::endl;
}
