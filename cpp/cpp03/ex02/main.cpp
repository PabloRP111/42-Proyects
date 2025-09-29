/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/02 13:05:55 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	FragTrap a("Charmander");
	ScavTrap b("Nintendo_sues_for_copyright_infringement_mon");
	FragTrap c(a);
	std::cout << std::endl;
	
	a.highFivesGuys();
	a.attack(b.getName());
	std::cout << a.getName() << " has " << a.getEnergyPts() << " energy points." << std::endl;
	b.takeDamage(a.getAttackDmg());
	std::cout << std::endl;

	a.beRepaired(10);
	std::cout << std::endl;
}
