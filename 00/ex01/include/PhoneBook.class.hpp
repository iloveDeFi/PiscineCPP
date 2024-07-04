/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:43:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 16:41:05 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {
    private:
        static const int _MAX_CONTACTS = 8;
        Contact _contacts[_MAX_CONTACTS];
        int _currentIndex;
    
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact(const Contact& contact);
        void search() const;
        Contact getContact(int index) const;
        void displayOneContact(int _currentIndex) const;
        void displayAllContacts() const;
        void exit() const;
};

#endif
