/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:01:17 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/14 08:48:07 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits.h>
#include <cfloat>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
public:
    static void convert(std::string const &literal);

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter & operator=(const ScalarConverter &);
};

#endif
