/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:00:42 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/14 09:28:40 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(std::string lit)
{
    return lit.length() == 1 && std::isprint(lit[0]) && !std::isdigit(lit[0]);
}

bool isInt(std::string lit)
{
    int i = 0;

    if (lit[i] == '+' || lit[i] == '-')
        i++;
    for (int aux = i; aux <  static_cast<int>(lit.size()); aux++)
    {
        if (!std::isdigit(lit[aux]))
            return false;
    }
    return true;
}

bool isFloat(std::string lit)
{
    int i = 0;
    int np = 0;

    if (lit.size() < 4)
        return false;
    if (lit[i] == '+' || lit[i] == '-')
        i++;
    for (int aux = i; aux < (static_cast<int>(lit.size() - 1)); aux++)
    {
        if (np > 1)
            return false;
        if ((!std::isdigit(lit[aux])) && (lit[aux] != '.'))
            return false;
        if (lit[aux] == '.')
            np++;
    }
    if (np != 1)
        return false;
    if (lit[(lit.size() - 1)] != 'f')
        return false;
    return true;
}

bool isDouble(std::string lit)
{
    int i = 0;
    int np = 0;

    if (lit.size() < 3)
        return false;
    if (lit[i] == '+' || lit[i] == '-')
        i++;
    for (int aux = i; aux < (static_cast<int>(lit.size() - 1)); aux++)
    {
        if (np > 1)
            return false;
        if (!std::isdigit(lit[aux]) && (lit[aux] != '.'))
            return false;
        if (lit[aux] == '.')
            np++;
    }
    if (np != 1)
        return false;
    return true;
}

bool isPseudoLiteral(std::string lit)
{
    if (lit == "-inff" || lit == "+inff" || lit == "nanf" || lit == "-inf"
        || lit == "+inf" || lit == "nan")
        return true;
    return false;
}

void printChar(std::string lit)
{
    char c = lit[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<int>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
}

void printInt(std::string lit)
{
    char *endStr;
    long longN = std::strtol(lit.c_str(), &endStr, 10);

    if (*endStr != '\0')
        std::cout << "There was non valid characters" << std::endl;
    else
    {
        // char
        if (longN < 0 || longN > 255)
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<char>(longN)))
            std::cout << "char: '" << static_cast<char>(longN) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // int
        if (longN < INT_MIN || longN > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(longN) << std::endl;

        // float
        if (longN < -FLT_MAX || longN > FLT_MAX)
            std::cout << "float: impossible" << std::endl;
        else
        {
            if (longN <= 999999)
                std::cout << "float: " << static_cast<float>(longN) << ".0f" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(longN) << "f" << std::endl;
        }

        // double
        if (longN > 999999)
            std::cout << "double: " << static_cast<double>(longN) << std::endl;
        else
            std::cout << "double: " << static_cast<double>(longN) << ".0" << std::endl;
    }
}

void printDecimals(double doubleF)
{
    // char
    if (doubleF < 0 || doubleF > 255)
        std::cout << "char: impossible" << std::endl;
    else if (doubleF >= INT_MIN && doubleF <= INT_MAX) {
        int n = static_cast<int>(doubleF);
        if (std::isprint(static_cast<char>(n)))
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int
    if (doubleF < INT_MIN || doubleF > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(doubleF) << std::endl;

    // float
    if (doubleF < -FLT_MAX || doubleF > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else {
        float f = static_cast<float>(doubleF);
        std::cout << "float: " << f;
        if (std::floor(f) == f) // Si no hay decimales
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // double
    std::cout << "double: " << doubleF;
    if (std::floor(doubleF) == doubleF) // Si no hay decimales
        std::cout << ".0";
    std::cout << std::endl;
}

void printPseudoLiteral(std::string lit)
{
    if (lit == "nanf" || lit == "+inff" || lit == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << lit << '\n';
        std::cout << "double: " << lit.substr(0, lit.length() - 1) << '\n'; // quitar f
    }
    else if (lit == "nan" || lit == "+inf" || lit == "-inf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << lit << "f" << std::endl;
        std::cout << "double: " << lit << std::endl;
    }
    else
        std::cout << "A big error occurred" << std::endl;
}

void ScalarConverter::convert(std::string const &lit)
{
    double  doubleF = 0;

    if (lit.empty())
		std::cout << "literal is empty, imposible to convert any type" << std::endl;
	else if (isChar(lit)) {
        printChar(lit);
    } else if (isInt(lit)) {
        printInt(lit);
    } else if (isFloat(lit))
    {
        std::string clean = lit;
        if (!clean.empty() && clean[clean.length() - 1] == 'f')
            clean = clean.substr(0, clean.length() - 1);
        doubleF = std::strtod(clean.c_str(), NULL);
        printDecimals(doubleF);
    } else if (isDouble(lit))
    {
        doubleF = std::strtod(lit.c_str(), NULL);
        printDecimals(doubleF);
    } else if (isPseudoLiteral(lit)) {
        printPseudoLiteral(lit);
    } else {
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
