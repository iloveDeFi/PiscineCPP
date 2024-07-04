/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:41:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 18:47:09 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> // for std::setw means set field width
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main() {
    PhoneBook myPhoneBook;
    std::string command;
    int currentIndex = 0;
    std::cout << "PhoneBook is open. Use ADD, SEARCH or EXIT." << std::endl;

    while (true) {
        std::cout << "Commande : ";
        std::cin >> command;

        if (command == "ADD") {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

            std::cout << "Enter first name : ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter nickname : ";
            std::cin >> nickName;
            std::cout << "Entrer phone number : ";
            std::cin >> phoneNumber;
            std::cout << "Enter darkest secret : ";
            std::cin.ignore(); // Ignore reamaining newline in buffer
            std::getline(std::cin, darkestSecret);

            if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty()) {
                std::cerr << "Erroritos, fields can't be emptitos." << std::endl;
            } else {
                Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret, currentIndex);
                myPhoneBook.addContact(newContact);
            }
         } else if (command == "SEARCH") {
            myPhoneBook.search();
        } else if (command == "EXIT") {
            std::cout << "Adios amigos!" << std::endl;
            break;
        } else {
            std::cerr << "Commande non reconnue. Utilisez ADD, SEARCH ou EXIT." << std::endl;
        }
    }
    return (0);
}
