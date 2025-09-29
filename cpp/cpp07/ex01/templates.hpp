/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:17:43 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/01 11:54:02 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template<typename T>
void iter(T *array, int len, void(*func)(T&)) {
    for (int i = 0; i < len; i++)
        func(array[i]);
}

template<typename T>
void iter(T *array, int len, void(*func)(const T&)) {
    for (int i = 0; i < len; i++)
        func(array[i]);
}

#endif