/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:39:13 by bat               #+#    #+#             */
/*   Updated: 2024/07/04 19:04:26 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _currentIndex(0) {}

PhoneBook::~PhoneBook() {
    // no dynamic ressources to free = empty destructor
}

// Function to truncate strings longer than 10 characters and append a dot
std::string truncate(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::addContact(const Contact& contact) {
    if (_currentIndex < _MAX_CONTACTS) {
        _contacts[_currentIndex] = contact;
        ++_currentIndex;
    } else {
        // If full replace my oldest contact
        std::cout << "PhoneBook is full. Oldest contact remplaced." << std::endl;
        _contacts[0] = contact;
    }
}

void PhoneBook::search() const {
    if (_currentIndex == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "Prénom" << "|"
              << std::setw(10) << "Nom" << "|"
              << std::setw(10) << "Surnom" << std::endl;

    for (int i = 0; i < _currentIndex; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter contact index you need : ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= _currentIndex) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Error. Invalid index." << std::endl;
    } else {
        const Contact& contact = _contacts[index];
        std::cout << "First Name     : " << contact.getFirstName() << std::endl;
        std::cout << "Last Name      : " << contact.getLastName() << std::endl;
        std::cout << "Nickname       : " << contact.getNickname() << std::endl;
        std::cout << "Phone Number   : " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret : " << contact.getDarkestSecret() << std::endl;
    }
}
