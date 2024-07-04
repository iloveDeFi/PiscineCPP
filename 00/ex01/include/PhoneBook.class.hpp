/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:43:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 14:14:31 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact(const Contact& contact);
        void displayOneContact(int index) const;
        void displayAllContacts() const;
        void exit() const;

    private:
        static const int _MAX_CONTACTS = 8;
        Contact _contacts[_MAX_CONTACTS];

        int _currentIndex;
};

#endif
