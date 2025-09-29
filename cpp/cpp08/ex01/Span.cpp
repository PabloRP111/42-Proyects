/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:09:40 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 08:02:20 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _spanMax(10000) {}

Span::Span(int n) : _spanMax(n) {}

Span::Span(const Span &sp) : _spanMax(sp._spanMax), _spanContainer(sp._spanContainer) {}

Span &Span::operator=(const Span &sp) 
{
	if (&sp != this)
	{
		_spanMax = sp._spanMax;
		_spanContainer = sp._spanContainer;
	}
	return *this;
}

Span::~Span() {}

const char*  Span::FewNumbersSpanException::what() const throw()
{
	return "Few Numbers Span Exception";
}

const char*  Span::FullSpanException::what() const throw()
{
	return "Full Span Exception";
}

const char*  Span::NotIntegerException::what() const throw()
{
	return "Number Not a Integer Exception";
}

void	Span::addNumber(int n) 
{
	if (n > INT_MAX || n < INT_MIN)
		throw NotIntegerException();
	if (_spanContainer.size() < static_cast<std::size_t>(_spanMax))
		_spanContainer.push_back(n);
	else
		throw FullSpanException();
}

int		Span::shortestSpan()
{
	if (_spanContainer.size() > 1)
	{
		std::vector<int> sorted = _spanContainer;
   		std::sort(sorted.begin(), sorted.end());
		int span = sorted[1] - sorted[0];

		for (size_t i = 1; i < sorted.size() - 1; i++)
		{
			//std::cout << "sorted[" << i << "] " << sorted[i] << ", sorted[" << i << " + 1]" << sorted[i + 1 ] << std::endl;
			if ((sorted[i + 1] - sorted[i]) < span)
				span = (sorted[i + 1] - sorted[i]);
			//std::cout << " span" << span << std::endl;
		}
		return span;
	}
	else
		throw FewNumbersSpanException();
}

int		Span::longestSpan() 
{
	if (_spanContainer.size() > 1)
	{
		std::vector<int> sorted = _spanContainer;
   		std::sort(sorted.begin(), sorted.end());
		int min = *std::min_element(sorted.begin(), sorted.end());
		int max = *std::max_element(sorted.begin(), sorted.end());
		return max - min;
	}
	else
		throw FewNumbersSpanException();
}
