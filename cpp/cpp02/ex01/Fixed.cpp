/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:32:20 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/19 13:10:16 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

// Inicialización de la variable estática
const int Fixed::_fractionalBits = 8;

//Constructor Default
Fixed::Fixed() : _value(0) { // Inicializa valor
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    _value = value << _fractionalBits; //siempre que movemos 8 bits, es como multiplicar por la potencia 2^8 (256)
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fractionalBits)); //aqui se hace lo mismo, pero como no puedes hacer << con float lo haces con 1
    std::cout << "Float constructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other._value;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// Getters / Setters
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

// Funciones de la clase
float Fixed::toFloat( void ) const
{
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (_value / (1 << _fractionalBits));
}

//Sobrecarga
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

