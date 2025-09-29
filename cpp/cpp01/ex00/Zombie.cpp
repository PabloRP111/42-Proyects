/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:06:48 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 07:59:42 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Métodos de Zombie
Zombie::Zombie(std::string namez) : name(namez){}
Zombie::Zombie(){}
Zombie::~Zombie(){std::cout << "Zombie " << getName() << " destroyed" << std::endl;}

std::string Zombie::getName() const {
    return name;
}

void Zombie::setName(std::string namez){
    name = namez;
}

void	Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
