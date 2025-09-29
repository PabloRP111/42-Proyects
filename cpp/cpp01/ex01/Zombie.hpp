/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:07:25 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 16:07:50 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();

		void		announce();
		void 		setName(std::string name);
		std::string	getName() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
