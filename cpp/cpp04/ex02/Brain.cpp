/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:41:27 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/30 07:45:41 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor & Destructor
Brain::Brain() {
    std::cout << "Brain created with default constructor" << std::endl;
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain created with copy constructor" << std::endl;
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

//Getters & Setters
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "";
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}
