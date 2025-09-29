/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:17:50 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/28 16:35:43 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"

int main()
{
	int a = 1;
	int b = 2;

	std::cout << "The minimum between a(" << a << ") and b(" << b << ") it´s  " << min(a, b) << std::endl;
	std::cout << "The maximum between a(" << a << ") and b(" << b << ") it´s  " << max(a, b) << std::endl;

	swap(a, b);
	std::cout << "Now, int A = " << a << " int B = " << b << std::endl;

	char ac = 'a';
	char bc = 'b';

	std::cout << "The minimum between a(" << ac << ") and b(" << bc << ") it´s  " << min(ac, bc) << std::endl;
	std::cout << "The maximum between a(" << ac<< ") and b(" << bc << ") it´s  " << max(ac, bc) << std::endl;

	swap(ac, bc);
	std::cout << "Now, char A = " << ac << " char B = " << bc << std::endl;
}
