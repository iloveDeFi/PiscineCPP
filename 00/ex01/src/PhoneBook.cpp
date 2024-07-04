/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:39:13 by bat               #+#    #+#             */
/*   Updated: 2024/07/04 13:49:55 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _currentIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
    if (_currentIndex < _MAX_CONTACTS) {
        _contacts[_currentIndex++] = contact;
    } else {
        // If full replace my oldest contact
        std::cout << "PhoneBook is full. Oldest contact remplaced." << std::endl;
        _contacts[0] = contact;
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
    delete this;
    std::cout << "Exiting PhoneBook..." << std::endl;
}