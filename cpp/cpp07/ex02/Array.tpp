/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:30:35 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/28 16:39:56 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        } else {
            _data = NULL;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
    return "Array index out of bounds";
}
