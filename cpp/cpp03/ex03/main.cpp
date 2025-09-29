/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/04 08:59:48 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap a("Charmander");
	DiamondTrap b("Nintendo_sues_for_copyright_infringement_mon");
	DiamondTrap c(a);
	std::cout << std::endl;
	
	a.whoAmI();
	std::cout << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDmg());
	std::cout << std::endl;

	a.beRepaired(10);
	std::cout << std::endl;

	FragTrap d("squirtle");
	ScavTrap e("Bulbasur");
	std::cout << std::endl;
}
