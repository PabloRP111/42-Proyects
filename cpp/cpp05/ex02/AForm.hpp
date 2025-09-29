/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:26:38 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/09 09:13:41 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeSignature;
		int					_gradeExecution;
		const std::string 	_target;

	public:
		//Canonicals Methods
		AForm();
		AForm(const std::string &name, bool isSigned, int gradeSig, int gradeExec, const std::string &target);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		// Getters y Setters
		const std::string	&getName() const;
		const std::string	&getTarget() const;
		bool				getSigned() const;
		int					getGradeSignature() const;
		int					getGradeExecution() const;
		void				setSigned(bool sign);
		void				setGradeSignature(int grade);
		void				setGradeExecution(int grade);

		// Methods
		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		virtual void	print(std::ostream &os) const = 0;


		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class IsNotSigned : public std::exception {
			public:
				const char* what() const throw();
		};
		class EnoughtGrade : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
