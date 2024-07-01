/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:42:35 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/01 15:22:07 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {
    private:
        char* name;
    protected:
    public:
        // Canonical form for my class
        // Constructuer par defaut (CD)
        Contact() : name(nullptr) {
            std::cout << "Default constructor called" << std::endl;
        }
        // Constructeur parametre (CP)
        Contact(const char *name)
        {
            std::cout << "Param constructor called" << std::endl;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        // Constructuer de copie (CC)


        // Operateur daffectation par copie (OAC)

        
        // Destructeur (D)
        ~Contact()
        {
            std::cout << "Destructor called" << std::endl;
            delete[] name;
        }
};

#endif