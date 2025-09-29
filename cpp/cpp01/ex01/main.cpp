/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:03:10 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 16:11:24 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;

	Zombie *zombies = zombieHorde(N, "Unders");
	if (zombies)
	{
		for (int i = 0; i < N; i++)
			zombies[i].announce();
		delete []zombies;
	}
}
