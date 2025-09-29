/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:30:43 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/01 07:58:53 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;

    class IndexOutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"

#endif
