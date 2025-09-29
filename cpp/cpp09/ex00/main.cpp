/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:46:25 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/20 20:16:11 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Error, too arguments" << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange	historical;
		historical.printHistoricalPrices(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
