/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:41:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/03 11:58:22 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.h"
#include "PhoneBook.class.h"

using std::cout;
using std::cin;

// SEARCH
// // Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
// de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
// un point (’.’).
// Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// Sinon, affichez les informations du contact, une par ligne.
 // INDEX | FIRST NAME | LAST NAME | NICKNAME



int main (void)
{
    char    buff[512];

    cout << "Enter your command: ";
    cin >> buff;
    
    void check_entry()
    {
        if (buff == "ADD")
            add_new_contact(nullptr);
        else if (buff == "SEARCH")
            search_contact(nullptr)
        else if (buff == "EXIT")
            exit_delete_contact(nullptr);
        else 
            continue ;
    }
    return (0);
}