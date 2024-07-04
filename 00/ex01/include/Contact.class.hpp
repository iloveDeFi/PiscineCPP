/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:42:35 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 14:14:46 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DECLARATION OF MY CLASS
// (POD CLASS - Plain Old Data)

#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>
class Contact {
private:
    std::string _phone_number;
    std::string _darkest_secret;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    int _index;

public:
    // My constructors here
    Contact();
    Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
            const std::string& phoneNumber, const std::string& darkestSecret, int index);
    ~Contact();

    // My Setters && Getters methods here
    void setPhoneNumber(const std::string& phoneNumber);
    std::string getPhoneNumber() const;

    void setDarkestSecret(const std::string& darkestSecret);
    std::string getDarkestSecret() const;

    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;

    void setLastName(const std::string& lastName);
    std::string getLastName() const;

    void setNickname(const std::string& nickname);
    std::string getNickname() const;

    void setIndex(int index);
    int getIndex() const;
};

#endif
