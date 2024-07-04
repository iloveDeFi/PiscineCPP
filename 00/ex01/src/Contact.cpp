/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:41:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 13:37:48 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

// Constructor by default
Contact::Contact()
    : _phone_number(""), _darkest_secret(""), _first_name(""), _last_name(""), _nickname(""), _index(0) {
}

// Constructor with parameters to init my members
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
                 const std::string& phoneNumber, const std::string& darkestSecret, int index)
    : _phone_number(phoneNumber), _darkest_secret(darkestSecret), _first_name(firstName),
      _last_name(lastName), _nickname(nickname), _index(index) {
}

// My destructor
Contact::~Contact() {
    
}

// MY SETTERS
void Contact::setPhoneNumber(const std::string& phoneNumber) {
    _phone_number = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    _darkest_secret = darkestSecret;
}

void Contact::setFirstName(const std::string& firstName) {
    _first_name = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    _last_name = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    _nickname = nickname;
}

void Contact::setIndex(int index) {
    _index = index;
}

// MY GETTERS
std::string Contact::getPhoneNumber() const {
    return _phone_number;
}

std::string Contact::getDarkestSecret() const {
    return _darkest_secret;
}

std::string Contact::getFirstName() const {
    return _first_name;
}

std::string Contact::getLastName() const {
    return _last_name;
}

std::string Contact::getNickname() const {
    return _nickname;
}

int Contact::getIndex() const {
    return _index;
}
