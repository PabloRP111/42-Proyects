/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:42:20 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/20 17:55:21 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//PhoneBook
PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}
PhoneBook::~PhoneBook(){}

//Seters y Getters
void PhoneBook::setContact(Contact ctact, int i){
    contacts[i] = ctact;
}

Contact PhoneBook::getContact(int i) const{
    return contacts[i];
}

void PhoneBook::setCurrentIndex(int current_index){
    currentIndex = current_index;
}

void PhoneBook::setTotalContacts(int total_contacts){
    totalContacts = total_contacts;
}

int	PhoneBook::getCurrentIndex() const {
    return currentIndex;
}

int PhoneBook::getTotalContacts() const {
    return totalContacts;
}

// Métodos de PhoneBook
int PhoneBook::checkAux(std::string aux){
    size_t start = aux.find_first_not_of(" \t");
    if (start != std::string::npos) {
        aux = aux.substr(start);
    } else {
        aux.clear();
    }
    if (aux.empty())
        return (0);
    return (1);
}

std::string PhoneBook::ask(std::string question) {
    std::string aux = "";
    while (checkAux(aux) != 1)
    {
        std::cout << question;
        if (!std::getline(std::cin, aux))
        {
            std::cout << "\nEOF detected. Finishing the program.\n";
            exit(1);
        }
    }
    return aux;
}

std::string PhoneBook::trimTen(std::string str){
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str = str.append(".");
    }
    else if(str.length() < 10)
        str = std::string(10 - str.length(), ' ') + str; 
    return str;
}

void PhoneBook::searchContact(){
    Contact     currentContact;
    std::string aux;
    int         total_contacts = getTotalContacts();
    int         i = 0;

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|   Index  |First Name| Last Name| Nick Name|PhoneNumbe|" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    while (i < total_contacts)
    {
        currentContact = getContact(i);
        std::cout << "-";
        std::cout << "         " << i + 1;

        std::cout << "|";
        aux = trimTen(currentContact.getFirstName());
        std::cout << aux;
        std::cout << "|";
        
        aux = trimTen(currentContact.getLastName());
        std::cout << aux;
        std::cout << "|";
        
        aux = trimTen(currentContact.getNickName());
        std::cout << aux;
        std::cout << "|";

        aux = trimTen(currentContact.getPhoneNumber());
        std::cout << aux;
        std::cout << "-" << std::endl;
        i++;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    
	int format = 0;
    while (format == 0)
    {
        format = 1;
        aux = ask("Please tell me the contact number (between 1-8), that you want yo watch\n");

        if (!std::isdigit(aux[0]))
            format = 0;
		if (aux[0] > 56 || aux[0] < 49)
			format = 0;
        if (aux.length() != 1)
            format = 0;
        if (format == 0)
            std::cout << "Incorrect format, must be only a number between 1-8" << std::endl;
    }
    int index = atoi(aux.c_str()) - 1;
	currentContact = getContact(index);

    if (index + 1 <= getTotalContacts())
    {
        std::cout << "FisrtName: " << currentContact.getFirstName() << std::endl;
        std::cout << "LastName: " << currentContact.getLastName() << std::endl;
        std::cout << "NickName: " << currentContact.getNickName() << std::endl;
        std::cout << "PhoneNumber: " << currentContact.getPhoneNumber() << std::endl;
        std::cout << "DarkestSecret: " << currentContact.getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Unexist contact" << std::endl;
}

void PhoneBook::addContact() {
    int current_index = getCurrentIndex();
    int total_contacts = getTotalContacts();
    std::string aux;
    
    if (total_contacts < 8)
    {
        total_contacts++;
        setTotalContacts(total_contacts);
    }
    aux = ask("What´s your First Name\n");
    contacts[currentIndex].setFirstName(aux);
    std::cout << std::endl;

    aux = ask("What´s your Last Name\n");
    contacts[currentIndex].setLastName(aux);
    std::cout << std::endl;

    aux = ask("What´s your Nick Name\n");
    contacts[currentIndex].setNickName(aux);
    std::cout << std::endl;

    int format = 0;
    while (format == 0)
    {
        format = 1;
        aux = ask("What´s your Phone Number\n");

        for (size_t i = 0; i < aux.length(); ++i) {
            if (!std::isdigit(aux[i]))
                format = 0;
        }
        if (aux.length() != 9)
            format = 0;
        if (format == 0)
            std::cout << "Incorrect format, must be only nine numbers" << std::endl;
    }
    contacts[currentIndex].setPhoneNumber(aux);
    std::cout << std::endl;

    aux = ask("What´s your Darkest Secret\n");
    contacts[currentIndex].setDarkestSecret(aux);
    std::cout << std::endl;

    current_index = (current_index + 1) % 8; // Indice circular
    setCurrentIndex(current_index);
}
