/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:42:29 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 14:34:09 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	int exit = 1;
	std::string input;
	PhoneBook agenda;

	while (exit == 1)
	{
		std::cout << "\nChoose an option:\n\t1. ADD (a contact) \n\t2. SEARCH (a contact)\n\t3. EXIT" << std::endl;

		if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected. Finishing the program.\n";
            break;
        }

		if (input == "ADD")
		{
			std::cout << "\nADD a Contact\n----------------\n";
			agenda.addContact();
		}
		else if (input == "SEARCH")
		{
			std::cout << "\nSEARCH a Contact\n----------------\n";
			agenda.searchContact();
		}
		else if (input == "EXIT")
		{
			exit = 0;
			std::cout << "\nEnd of program";
		}
		else
			std::cout << "\nUnknown comand, please try again";
		std::cout << std::endl;
	}
}
