/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:00:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/04 10:10:54 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat bureaucrat;
	Bureaucrat bureaucrat2("Pablo", 1);
	
	std::cout << bureaucrat << std::endl;
	try {
		bureaucrat.decreaseGrade();	
	} catch (const std::exception& e) {
        std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	bureaucrat.increaseGrade();
	std::cout << bureaucrat << std::endl;

	std::cout << std::endl;
	std::cout << bureaucrat2 << std::endl;
	try {
		bureaucrat2.increaseGrade();
	} catch (const std::exception& e) {
        std::cerr << "Exception catched: " << e.what() << std::endl;
    }
	bureaucrat2.decreaseGrade();
	std::cout << bureaucrat2 << std::endl;
}
