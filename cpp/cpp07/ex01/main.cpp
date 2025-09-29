/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:17:50 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/09 10:10:22 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"

template <typename T>
void increment(T& x) {
    x += 1;
    std::cout << x << " ";
}

void pair(int &n)
{
	n /= 2;
	std::cout << n << " ";
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	char str[5] = "Gnk`";
	
	iter(arr, 5, increment<const int>);
	std::cout << std::endl;

	std::cout << std::endl;
	iter(str, 4, increment<const char>);
	std::cout << std::endl;
	std::cout << std::endl;

	iter(arr, 5, pair);
	std::cout << std::endl;
}
