/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:37:29 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/19 09:21:02 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {
	Harl	Harl;

	Harl.complain("debug");
	Harl.complain("info");
	Harl.complain("warning");
	Harl.complain("error");
	Harl.complain("other");
	return 0;
}
