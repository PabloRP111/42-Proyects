/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:44:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 16:50:44 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *pstr = &str;
	std::string &strref = str;

	std::cout << "Dirección de memoria str: " << &str << std::endl;
	std::cout << "Dirección de memoria pstr: " << pstr << std::endl;
	std::cout << "Dirección de memoria stref: " << &strref << std::endl;
	std::cout << std::endl;

	std::cout << "Valor str: " << str << std::endl;
	std::cout << "Valor pstr: " << *pstr << std::endl;
	std::cout << "Valor stref: " << strref << std::endl;
}
