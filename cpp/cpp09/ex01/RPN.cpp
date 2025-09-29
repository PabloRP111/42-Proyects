/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:32:08 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/22 09:45:54 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *RPN::BadInputException::what() const throw() {
	return "Error";
}

const char *RPN::ZeroDivideException::what() const throw() {
	return "Error dividing by zero, are you triyindg screw me??? ;(";
}

bool	RPN::checkFormat(std::string line)
{
	if (line.length() < 5)
		return false;

	int	nNumbers = 0;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (i % 2 != 0 && line[i] != ' ')
			return false;
		if (i % 2 == 0 && (!isdigit(line[i]) && (line[i] != '+' && line[i] != '-'
			&& line[i] != '/' && line[i] != '*')))
			return false;
		if (isdigit(line[i]))
			nNumbers++;
		if (line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '*')
		{
			if (nNumbers < 2)
				return false;
			nNumbers--;
		}
	}
	if (nNumbers != 1)
		return false;
	return true;
}

RPN::RPN() {}

RPN::RPN(std::string args)
{
	int i = 0;
	int a;
	int b;

	if (!checkFormat(args))
		throw BadInputException();
	while (args[i])
	{
		if (std::isdigit(args[i]))
			_operations.push(args[i] - '0');
		else if(args[i] != ' ')
		{
			a = this->_operations.top();
			this->_operations.pop();
			b = this->_operations.top();
			this->_operations.pop();
			if (args[i] == '+')
				this->_operations.push(b + a);
			else if (args[i] == '-')
				this->_operations.push(b - a);
			else if (args[i] == '*')
				this->_operations.push(b * a);
			else
			{
				if (a != 0)
					this->_operations.push(b / a);
				else
					throw ZeroDivideException();
			}
		}
		i++;
	}
	std::cout << this->_operations.top() << std::endl;
}

RPN::RPN(const RPN &calculator) {
	_operations = calculator._operations;
}

RPN &RPN::operator=(const RPN &calculator)
{
	if (this != &calculator)
	{
		this->_operations = calculator._operations;
	}
	return *this;
}

RPN::~RPN() {}
