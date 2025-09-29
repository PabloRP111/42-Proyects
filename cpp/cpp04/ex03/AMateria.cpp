/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:38:30 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/04 13:57:17 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unassigned") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other)
        _type = other._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    (void)target;
}
