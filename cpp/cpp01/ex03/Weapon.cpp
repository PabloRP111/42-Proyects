/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:48:09 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/17 16:35:38 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Métodos de Weapon
Weapon::Weapon(std::string type) : type(type){}
Weapon::~Weapon(){}

const std::string &Weapon::getType() const{
    const std::string &typeref = type;
    return typeref;
}

void Weapon::setType(std::string newtype){
    type = newtype;
}
