/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:20 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/26 10:19:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {}

Inter& Intern::operator=(const Intern &intern);

Intern::~Intern() {}

Form* makeForm(const std::string formName, std::string &target const) {
    try {
        if (formName != AForm.getName()) {
            throw std::exception();
        }
        else {
            std::cout << "Inter creates" << target.getName() << std::endl;
        }

    } catch (std::exception &e) {
        
    }
}


try {
        Bureaucrat john("John", 151); // Devrait lancer une exception
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }