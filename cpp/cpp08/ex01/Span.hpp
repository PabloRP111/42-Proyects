/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:09:59 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 08:01:29 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

class Span {
	private:
		unsigned int		_spanMax;
		std::vector<int>	_spanContainer;

	public:
		Span();
		Span(int n);
		Span(const Span &sp);
		Span &operator=(const Span &sp);
		~Span();

		class FewNumbersSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class FullSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class NotIntegerException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
};

#endif