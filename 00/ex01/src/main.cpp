/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:41:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/04 14:14:48 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.class.hpp"

int main() {
    PhoneBook myPhoneBook;
    std::string command;

    std::cout << "Bienvenue dans votre carnet d'adresses ! Utilisez les commandes ADD, SEARCH ou EXIT." << std::endl;

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

            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            myPhoneBook.addContact(newContact);

        } else if (command == "SEARCH") {
            myPhoneBook.displayContacts();

            int index;
            std::cout << "Entrez l'index du contact à afficher : ";
            std::cin >> index;

            if (std::cin.fail()) {
                std::cerr << "Erreur : index invalide." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            if (index >= 0 && index < myPhoneBook.getSize()) {
                Contact contact = myPhoneBook.getContact(index);
                std::cout << "Informations du contact :" << std::endl;
                std::cout << "Prénom         : " << contact.getFirstName() << std::endl;
                std::cout << "Nom de famille : " << contact.getLastName() << std::endl;
                std::cout << "Surnom         : " << contact.getNickname() << std::endl;
                std::cout << "Numéro de tel. : " << contact.getPhoneNumber() << std::endl;
                std::cout << "Plus lourd secret : " << contact.getDarkestSecret() << std::endl;

            } else {
                std::cerr << "Erreur : index hors de portée." << std::endl;
            }

        } else if (command == "EXIT") {
            std::cout << "Au revoir !" << std::endl;
            break;

        } else {
            std::cout << "Commande non reconnue. Utilisez ADD, SEARCH ou EXIT." << std::endl;
        }
    }

    return 0;
}
