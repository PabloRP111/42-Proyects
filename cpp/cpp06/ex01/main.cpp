/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:00:49 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/07 13:02:12 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data d = {1, "Datos"};

	uintptr_t intPtr = Serializer::serialize(&d);

	Data *d2 = Serializer::deserialize(intPtr);

	std::cout << "D: pointer " << &d << " id " << d.id << " name " << d.name << std::endl;
	std::cout << "D2: pointer " << d2 << " id " << d2->id << " name " << d2->name << std::endl;
}