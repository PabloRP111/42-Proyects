/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:48:07 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/17 16:34:50 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		~Weapon();

		void 				setType(std::string type);
		const std::string	&getType() const;
};

#endif
