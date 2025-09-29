/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:48:04 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/17 17:27:26 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*wp;

	public:
		HumanB(std::string name);
		~HumanB();

		void 		setName(std::string name);
		std::string	getName() const;
		void		setWeapon(Weapon &_wp);

		void		attack();
};

#endif