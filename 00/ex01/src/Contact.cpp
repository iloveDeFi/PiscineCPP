/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:41:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 18:15:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iomanip>

// Constructor by default
Contact::Contact()
    : _phoneNumber(""), _darkestSecret(""), _firstName(""), _lastName(""), _nickName(""), _index(0) {
}

// Constructor with parameters to init my members
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
                 const std::string& phoneNumber, const std::string& darkestSecret, int index)
    : _phoneNumber(phoneNumber), _darkestSecret(darkestSecret), _firstName(firstName),
      _lastName(lastName), _nickName(nickname), _index(index) {
}

// My destructor
Contact::~Contact() {
    
}

// ------------- MY SETTERS -------------

void Contact::setFirstName(const std::string& firstName) {
    _firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    _lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    _nickName = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    _darkestSecret = darkestSecret;
}

void Contact::setIndex(int index) {
    _index = index;
}

// ------------- MY GETTERS -------------

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickName;
}
std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

int Contact::getIndex() const {
    return _index;
}
