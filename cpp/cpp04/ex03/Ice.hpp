/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:29:36 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/02 11:25:22 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    ~Ice();

    AMateria *clone() const;
    using AMateria::use; // Esto evita ocultar funciones base con mismo nombre
    void use(ICharacter &target);
};

#endif
