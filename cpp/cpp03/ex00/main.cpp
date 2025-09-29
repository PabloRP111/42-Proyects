/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/24 09:51:28 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("Charmander");
	ClapTrap b("Nintendo_sues_for_copyright_infringement_mon");
	ClapTrap c(a);
	
	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	b.beRepaired(2);
	
	std::cout << std::endl;
	b.setAttackDmg(12);
	b.attack(a.getName());
	a.takeDamage(b.getAttackDmg());
	a.beRepaired(2);
	std::cout << std::endl;
}
