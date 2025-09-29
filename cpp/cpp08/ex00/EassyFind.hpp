/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EassyFind.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:58:40 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 07:42:53 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASSYFIND_HPP
#define EASSYFIND_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw(){
            return "Wanted Number Not Found Exception: The number is not in Container";
        }
};

template<typename T>
typename T::iterator easyfind(T &container, int wanted) {
    typename T::iterator it = std::find(container.begin(), container.end(), wanted);

    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif