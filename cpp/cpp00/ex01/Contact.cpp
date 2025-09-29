/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:42:40 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 13:29:55 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Métodos de Contact
Contact::Contact(){}
Contact::~Contact(){}

void Contact::setFirstName(const std::string& name) {
    firstName = name;
}

std::string Contact::getFirstName() const {
    return firstName;
}

void Contact::setLastName(const std::string& name) {
    lastName = name;
}

std::string Contact::getLastName() const {
    return lastName;
}

void Contact::setNickName(const std::string& nname) {
    nickName = nname;
}

std::string Contact::getNickName() const {
    return nickName;
}

void Contact::setPhoneNumber(const std::string& name) {
    phoneNumber = name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::setDarkestSecret(const std::string& name) {
    darkestSecret = name;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
