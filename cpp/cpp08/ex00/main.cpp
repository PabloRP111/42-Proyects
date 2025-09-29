/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:17:53 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 07:41:52 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EassyFind.hpp"

int main()
{
	int vals[] = {1,2,3,4,5,6,7,8,9,0};
	std::vector<int> numbersV;
	std::list<int> numbersL;

	for (int i = 0; i < 10; i++)
	{
		numbersV.push_back(vals[i]);
		if (i != 9)
			numbersL.push_back(vals[i]);
	}

	try
	{
		std::cout << "Searching int in vector: ";
		int pos = std::distance(numbersV.begin(), easyfind(numbersV, 0));
		std::cout << "int finded in pos " << pos << " of the container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Searching int in list: ";
		int pos = std::distance(numbersL.begin(), easyfind(numbersL, 0));
		std::cout << "int finded in pos " << pos << " of the container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
