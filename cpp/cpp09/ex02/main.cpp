/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:54:37 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/16 10:09:03 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int toInt(const char* s) {
    std::stringstream ss(s);
    int n;
    ss >> n;
    if (ss.fail()) {
        throw std::runtime_error("Error, Bad Input");
    }
    return n;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;

	int i = 0;
	int j = -1;
	std::vector<int>	c;
	std::deque<int>		c2;

	try
	{
		while (argv[++i])
		{
			if (argv[i][0] == '\0')
				continue;
			while (argv[i][++j])
			{
				if (j == 0 && argv[i][j] == '+')
					continue;
				if (!std::isdigit(argv[i][j]))
				{
					std::cout << "Error, Bad Input" << std::endl;
					return 1;
				}
			}
			int n = toInt(argv[i]);
			c.push_back(n);
			c2.push_back(n);
			j = 0;
		}

		PMergeMe m;
		m.fordJohnson(c2, "deque");
		m.fordJohnson(c, "vector");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
