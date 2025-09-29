/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:26:30 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 09:16:26 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Ordinal Form"), _signed(false), _gradeSignature(150), _gradeExecution(150) {}

Form::Form(const std::string &name, bool isSigned, int gradeSig, int gradeExec) : _name(name) 
{
	_signed = isSigned;
	if (gradeSig < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSig > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();

	_gradeSignature = gradeSig;
	_gradeExecution = gradeExec;
}

Form::Form(const Form &other) : _name(other._name) 
{
	_signed = other._signed;
	_gradeSignature = other._gradeSignature;
	_gradeExecution = other._gradeExecution;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_gradeSignature = other._gradeSignature;
		_gradeExecution = other._gradeExecution;
	}
	return *this;
}

Form::~Form() {}

// Methods
const std::string	&Form::getName() const { return _name; }

bool				Form::getSigned() const { return _signed;}

int					Form::getGradeSignature() const { return _gradeSignature; }

int					Form::getGradeExecution() const { return _gradeExecution; }

void				Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeSignature)
	{
		std::cout << b.getName() << "  signed " << _name << std::endl;
		_signed = true;
	}
	else
		std::cout << b.getName() << " couldn’t sign " << _name << " because " << b.getName() << " grade it's too low." << std::endl;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Error in form degree, number to hight (maximun degree 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Error in form degree, number to low (minimum degree 150)";
}

std::ostream &operator<<(std::ostream& os, const Form &form)
{
	if (form.getSigned())
		os << form.getName() <<  " is signed, with grade " << form.getGradeSignature() << " to sign and grade " << form.getGradeExecution() << " to execute.";
	else
		os << form.getName() <<  " is not signed, with grade " << form.getGradeSignature() << " to sign and grade " << form.getGradeExecution() << " to execute.";
	return os;
}

