/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:03:51 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/24 09:37:18 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		// getters y setters
		std::string		getName();
		unsigned int	getHitPts();
		unsigned int	getEnergyPts();
		unsigned int	getAttackDmg();

		void			setName(std::string name);
		void			setAttackDmg(unsigned int amount);
		void			setHitPts(unsigned int amount);
		void			setEnergyPts(unsigned int amount);

};

#endif
