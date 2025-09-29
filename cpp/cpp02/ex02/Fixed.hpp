/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:33:14 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/24 08:16:44 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				_value;
		static const int	_fractionalBits;


	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
    	Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat( void ) const;
		int toInt( void ) const;

		// Comparaciones como métodos miembros:
    	bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;

		// Operadores aritméticos:
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		//min max
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed& b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
