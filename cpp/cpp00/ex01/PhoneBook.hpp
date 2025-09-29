/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:42:54 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/13 12:49:07 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "Contact.hpp"

// Clase PhoneBook
class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();
    ~PhoneBook();

	std::string	ask(std::string question);
	std::string trimTen(std::string str);
    void		addContact();
    void		printContact(int index);
    void		searchContact();
    int			checkAux(std::string aux);

    //Seters y Getters
    void	setContact(Contact ctact, int i);
	void	setCurrentIndex(int current_index);
    void	setTotalContacts(int total_contacts);
    Contact	getContact(int i) const;
    int		getCurrentIndex() const;
    int		getTotalContacts() const;
};

#endif
