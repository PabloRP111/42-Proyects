/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:32:06 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/22 09:41:42 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_operations;

	public:
		class BadInputException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class ZeroDivideException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		bool checkFormat(std::string line);

		RPN();
		RPN(std::string argv);
		RPN(const RPN &calculator);
		RPN &operator=(const RPN &calculator);
		~RPN();
};

#endif
