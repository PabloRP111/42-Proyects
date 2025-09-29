/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:19:56 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/19 09:23:39 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

std::string toLower(std::string str);

#endif