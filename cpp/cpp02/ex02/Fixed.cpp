/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:32:20 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/20 17:36:47 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Inicialización de la variable estática
const int Fixed::_fractionalBits = 8;

//Constructor Default
Fixed::Fixed() : _value(0) { // Inicializa valor
}

Fixed::Fixed(const int value) {
    _value = value << _fractionalBits; //siempre que movemos 8 bits, es como multiplicar por la potencia 2^8 (256)
}

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fractionalBits)); //aqui se hace lo mismo, pero como no puedes hacer << con float lo haces con 1
}

// Constructor de copia
Fixed::Fixed(const Fixed &other) {
    this->_value = other._value;
}

Fixed::~Fixed() {
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// Getters / Setters
int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
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

// Comparaciones como métodos miembros:
bool Fixed::operator==(const Fixed &other) const{
    if (other.getRawBits() == this->getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other) const{
    if (other.getRawBits() != this->getRawBits())
        return true;
    return false;
}


bool Fixed::operator<(const Fixed &other) const{
    if (this->getRawBits() < other.getRawBits())
        return true;
    return false;
}


bool Fixed::operator<=(const Fixed &other) const{
    if (this->getRawBits() <= other.getRawBits())
        return true;
    return false;
}


bool Fixed::operator>(const Fixed &other) const{
    if (this->getRawBits() > other.getRawBits())
        return true;
    return false;
}


bool Fixed::operator>=(const Fixed &other) const{
    if (this->getRawBits() >= other.getRawBits())
        return true;
    return false;
}

// Operadores aritméticos:
Fixed Fixed::operator+(const Fixed &other) const{
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}


Fixed Fixed::operator-(const Fixed &other) const{
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}


Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;

    int64_t mult = static_cast<int64_t>(this->_value) * static_cast<int64_t>(other._value);
    result.setRawBits(static_cast<int>(mult >> _fractionalBits));
    return result;
}


Fixed Fixed::operator/(const Fixed &other) const{
    Fixed result;

    if (other.getRawBits() == 0){
        std::cerr << "A dividir entre 0 pa tu casa crack" << std::endl;
        return result;
    }

    int64_t dividend = (static_cast<int64_t>(this->_value) << _fractionalBits);
    int64_t division = dividend / static_cast<int64_t>(other._value);
    result.setRawBits(static_cast<int>(division));
    return result;
}

Fixed &Fixed::operator++(){
    this->_value += 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->_value += 1;
    return temp;
}

Fixed &Fixed::operator--(){
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->_value -= 1;
    return temp;
}

//min max
Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a <= b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed& b){
    if (a <= b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (b > a)
        return b;
    else
        return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed& b){
    if (b > a)
        return b;
    else
        return a;
}
