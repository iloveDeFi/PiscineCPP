/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:41:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/03 12:07:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DEFINITION OF MY CLASS

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

Contact (void) {
    std::cout << "class Contact constructed" << std::endl;
}

~Contact (void) {
    std::cout << "class Contact destructed" << std::endl;
}

        // Constructuer par defaut (CD)
        Contact() : name(nullptr) {
           std::cout << "class Contact constructed" << std::endl;
        }
        // Constructeur parametre (CP)
        Contact(const char *name)
        {
            std::cout << "class Contact constructed with parameter" << std::endl;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        // Constructuer de copie (CC)


        // Operateur daffectation par copie (OAC)

        
        // Destructeur (D)
        ~Contact()
        {
            std::cout << "class Contact destructed" << std::endl;
            delete[] name;
        }

#endif