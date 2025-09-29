/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:43:32 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 10:20:04 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", false, 145, 137, "Pablo") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyForm", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(),
	other.getSigned(), other.getGradeSignature(), other.getGradeExecution(), other.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (&other != this)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::IsNotSigned();
	if (executor.getGrade() > this->getGradeExecution())
		throw AForm::EnoughtGrade();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::ofstream file((this->getTarget() + "_shrubbery").c_str()); //c_str conbvierte a std::string a const char*
	if (file.is_open()) {
		file << "   ^  " << std::endl;
		file << "  /|\\ " << std::endl;
		file << " /_|_\\" << std::endl;
		file << "   |  " << std::endl;
		file << "  / \\ " << std::endl;
		file << "      " << std::endl;
		file << "dedicate to " << this->getTarget() << std::endl;
		file.close();
		std::cout << this->getTarget() << " Shruberry has been planted!" << std::endl;
	}
}

void ShrubberyCreationForm::print(std::ostream &os) const {
	if (this->getSigned())
		os << this->getName() <<  "is a ShrubberyForm, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
	else
		os << this->getName() <<  " is a ShrubberyForm, not signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
}
