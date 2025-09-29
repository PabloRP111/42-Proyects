/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:26:30 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 10:21:07 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Ordinal Form"), _signed(false), _gradeSignature(150), _gradeExecution(150), _target("Pablo") {}

AForm::AForm(const std::string &name, bool isSigned, int gradeSig, int gradeExec, const std::string &target) : _name(name), _target(target)
{
	if (gradeSig < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSig > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	_signed = isSigned;
	_gradeSignature = gradeSig;
	_gradeExecution = gradeExec;
}

AForm::AForm(const AForm &other) : _name(other._name) 
{
	_signed = other._signed;
	_gradeSignature = other._gradeSignature;
	_gradeExecution = other._gradeExecution;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_gradeSignature = other._gradeSignature;
		_gradeExecution = other._gradeExecution;
	}
	return *this;
}

AForm::~AForm() {}

// Methods
const std::string	&AForm::getName() const { return _name; }

bool				AForm::getSigned() const { return _signed;}

const std::string	&AForm::getTarget() const { return _target; }

int					AForm::getGradeSignature() const { return _gradeSignature; }

int					AForm::getGradeExecution() const { return _gradeExecution; }

void	AForm::setSigned(bool sign) {this->_signed = sign;}

void	AForm::setGradeSignature(int grade) {this->_gradeSignature = grade;}

void	AForm::setGradeExecution(int grade) {this->_gradeExecution = grade;}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeSignature)
	{
		std::cout << b.getName() << " signed " << _name << std::endl;
		_signed = true;
	}
	else
		std::cout << b.getName() << " couldn’t sign " << _name << " because " << b.getName() << " grade it's too low." << std::endl;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Error in form degree, number to hight (maximun degree 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Error in form degree, number to low (minimum degree 150)";
}

const char* AForm::IsNotSigned::what() const throw() {
	return "Error in form execution, form isn´t singed";
}

const char* AForm::EnoughtGrade::what() const throw() {
	return "Error in form execution, bureaucrat hasn´t enought grade ;(";
}

void AForm::print(std::ostream &os) const {
	if (this->getSigned())
		os << this->getName() <<  " is signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
	else
		os << this->getName() <<  " is not signed, with grade " << this->getGradeSignature()
		   << " to sign and grade " << this->getGradeExecution() << " to execute.";
}

std::ostream &operator<<(std::ostream& os, const AForm &form)
{
	form.print(os);
	return os;
}
