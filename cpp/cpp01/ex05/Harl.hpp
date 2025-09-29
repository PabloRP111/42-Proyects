/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:37:32 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/19 08:51:24 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		void debug (void);
		void info (void);
		void warning (void);
		void error (void);

	public:
		Harl();
		~Harl();
	
		void complain(std::string level);
};

#endif
