/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:17:43 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/28 16:35:46 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T>
void swap(T &a, T &b) {
    T c = a;
	a = b;
	b = c;
}

#endif