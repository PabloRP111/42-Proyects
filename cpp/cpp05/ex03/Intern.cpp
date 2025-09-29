/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:00:35 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 12:38:03 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	if (&other != this)
		std::cout << "All the slaves-I mean Interns seem the same to me, EA said" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (&other != this)
		std::cout << "All the slaves-I mean Interns seem the same to me, EA said" << std::endl;
	return *this;
}

Intern::~Intern() {}

const char* Intern::UnknownForm::what() const throw() {
	return "The provided formName doesn´t exist";
}

AForm	*Intern::makeForm(const std::string formName, const std::string formTarget)
{
	int i = 0;
	std::string	forms[3] = {"robotomy request", "presidential request", "shruberry request"};

	for (; i < 3; i++)
	{
		if (forms[i] == formName)
			break;
	}

	AForm *form;
	switch (i)
	{
		case 0:
			form = new RobotomyRequestForm(formTarget);
			std::cout << "Intern creates " << *form << std::endl << std::endl;;
			break;
		case 1:
			form = new PresidentialPardonForm(formTarget);
			std::cout << "Intern creates " << *form << std::endl << std::endl;;
			break;
		case 2:
			form = new ShrubberyCreationForm(formTarget);
			std::cout << "Intern creates " << *form << std::endl << std::endl;;
			break;
		default:
				throw(Intern::UnknownForm());
			break;
	}
	return form;
}
