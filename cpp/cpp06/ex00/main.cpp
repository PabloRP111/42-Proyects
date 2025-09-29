/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:00:49 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/04 13:13:38 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << argv[i] << ":" << std::endl;
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl;
	}
}