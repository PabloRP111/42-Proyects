/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:00:03 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/07 11:09:11 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		//Canonicals Methods
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Methods
		const std::string	&getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm &f);

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

std::ostream &operator<<(std::ostream& os, const Bureaucrat	&bureaucrat);

#endif
