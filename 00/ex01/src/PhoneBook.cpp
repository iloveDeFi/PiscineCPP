/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:39:13 by bat               #+#    #+#             */
/*   Updated: 2024/07/04 16:45:55 by bat              ###   ########.fr       */
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
    if (_contactCount == 0) {
        std::cout << "Aucun contact enregistré." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "Prénom" << "|"
              << std::setw(10) << "Nom" << "|"
              << std::setw(10) << "Surnom" << std::endl;

    for (int i = 0; i < _contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Entrez l'index du contact à afficher : ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= _contactCount) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Erreur : index invalide." << std::endl;
    } else {
        const Contact& contact = _contacts[index];
        std::cout << "Prénom         : " << contact.getFirstName() << std::endl;
        std::cout << "Nom de famille : " << contact.getLastName() << std::endl;
        std::cout << "Surnom         : " << contact.getNickname() << std::endl;
        std::cout << "Numéro de tel. : " << contact.getPhoneNumber() << std::endl;
        std::cout << "Plus lourd secret : " << contact.getDarkestSecret() << std::endl;
    }
}

void PhoneBook::displayOneContact() const {
    std::cout << "Contact " << (_currentIndex + 1) << ":" << std::endl;
    std::cout << "First Name: " << _contacts[_currentIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[_currentIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[_currentIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[_currentIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[_currentIndex].getDarkestSecret() << std::endl;
    std::cout << "Index: " << _contacts[_currentIndex].getIndex() << std::endl;
    std::cout << std::endl;
}

void PhoneBook::displayAllContacts() const {
    for (int i = 0; i < _currentIndex; ++i) {
        std::cout << "Contact " << (i + 1) << ":" << std::endl;
        std::cout << "First Name: " << _contacts[i].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
        std::cout << "Phone Number: " << _contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[i].getDarkestSecret() << std::endl;
        std::cout << "Index: " << _contacts[i].getIndex() << std::endl;
        std::cout << std::endl;
    }
}

void    PhoneBook::exit() const {
    std::cout << "Exiting PhoneBook..." << std::endl;
    ~PhoneBook();
}