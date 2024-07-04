/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:41:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 16:54:13 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main() {
    PhoneBook myPhoneBook;
    std::string command;

    std::cout << "PhoneBook is open. Use ADD, SEARCH or EXIT." << std::endl;

    while (true) {
        std::cout << "Commande : ";
        std::cin >> command;

        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "Entrez le prénom : ";
            std::cin >> firstName;
            std::cout << "Entrez le nom de famille : ";
            std::cin >> lastName;
            std::cout << "Entrez le surnom : ";
            std::cin >> nickname;
            std::cout << "Entrez le numéro de téléphone : ";
            std::cin >> phoneNumber;
            std::cout << "Entrez le plus lourd secret : ";
            std::cin.ignore(); // Ignorer le newline restant dans le buffer
            std::getline(std::cin, darkestSecret);

            if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
                std::cerr << "Erroritos, fields can't be emptitos." << std::endl;
            } else {
                Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
                myPhoneBook.addContact(newContact);
            }
         } else if (command == "SEARCH") {
            myPhoneBook.search();
        } else if (command == "EXIT") {
            std::cout << "Au revoir !" << std::endl;
            break;
        } else {
            std::cerr << "Commande non reconnue. Utilisez ADD, SEARCH ou EXIT." << std::endl;
        }
    }
    return (0);
}
