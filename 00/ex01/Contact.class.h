/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:42:35 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/03 11:57:47 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DECLARATION OF MY CLASS
// (POD CLASS - Plain Old Data)

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

using std::string;
using std::integer;

// Canonical form for my class Contact
class Contact {
    private:
        string _phone_number;
        string _darkest_secret;
        string _first_name;
        string _last_name;
        string _nickname;
        integer _index;
        
    public:
        // Constructor by default
        Contact (void);

        // Constructor by copie
        Contact (const Contact& other);

        // Assignement Operator
        Contact & operator=(Contact const & rhs);
        Contact & operator+(Contact const & rhs) const;

        // Destrcutor = EXIT && DELETE
        ~Contact (void);
        
        // Public Methodes
        // Setter = ADD
        void setNewContact(const string& firstName);
        // Getter = SEARCH
        string getContact() const;
};

#endif