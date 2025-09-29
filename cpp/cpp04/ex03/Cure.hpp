/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:30:07 by prosas-p          #+#    #+#             */
/*   Updated: 2025/07/02 11:25:13 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& other);
    Cure &operator=(const Cure& other);
    ~Cure();

    AMateria* clone() const;
    using AMateria::use; // Esto evita ocultar funciones base con mismo nombre
    void use(ICharacter& target);
};

#endif
