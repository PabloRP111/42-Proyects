/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/02 13:07:40 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap a("Charmander");
	ScavTrap b("Nintendo_sues_for_copyright_infringement_mon");
	ScavTrap c(a);
	std::cout << std::endl;
	
	a.guardGate();
	b.attack(a.getName());
	std::cout << b.getName() << " has " << b.getEnergyPts() << " energy points." << std::endl;
	a.takeDamage(b.getAttackDmg());
	std::cout << std::endl;

	a.beRepaired(10);
	std::cout << std::endl;
}
