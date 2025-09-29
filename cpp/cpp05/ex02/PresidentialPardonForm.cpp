/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:44:32 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 10:19:06 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", false, 25, 5, "Pablo") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialForm", false, 25, 5, target)  {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(),
	other.getSigned(), other.getGradeSignature(), other.getGradeExecution(), other.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (&other != this)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw AForm::IsNotSigned();
	if (executor.getGrade() > this->getGradeExecution())
		throw AForm::EnoughtGrade();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::print(std::ostream &os) const {
	if (this->getSigned())
		os << this->getName() <<  "is a PresidentialPardonForm, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
	else
		os << this->getName() <<  " is a PresidentialPardonForm, not signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
}
