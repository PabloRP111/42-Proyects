/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:44:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 10:21:36 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotForm", false, 72, 45, "Pablo") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(),
	other.getSigned(), other.getGradeSignature(), other.getGradeExecution(), other.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (&other != this)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::IsNotSigned();
	if (executor.getGrade() > this->getGradeExecution())
		throw AForm::EnoughtGrade();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	if (std::rand() % 2 == 0)
    	std::cout << this->getTarget() << " has been robotomized!" << std::endl;
	else
    	std::cout << this->getTarget() << " failed the robotomy!" << std::endl;
}

void RobotomyRequestForm::print(std::ostream &os) const {
	if (this->getSigned())
		os << this->getName() <<  " is a RobotomyForm signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
	else
		os << this->getName() <<  " is a RobotomyForm not signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
}
