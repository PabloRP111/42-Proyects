/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:26:38 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 08:58:22 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeSignature;
		int					_gradeExecution;

	public:
		//Canonicals Methods
		Form();
		Form(const std::string &name, bool isSigned, int gradeSig, int gradeExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		// Methods
		const std::string	&getName() const;
		bool				getSigned() const;
		int					getGradeSignature() const;
		int					getGradeExecution() const;
		
		void				beSigned(Bureaucrat &b);

		// Exceptions
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &bureaucrat);

#endif
