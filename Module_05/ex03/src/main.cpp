/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/29 15:24:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "---------- EX03 TEST ----------" << std::endl;
    try {
        
        Intern intern;
        AForm *form;

        form = intern.makeForm("shrubbery creation", "Target0");
        std::cout << "Intern creates " << form->getName() << std::endl;
        delete form; 
        
        form = intern.makeForm("robotomy request", "Target1");
        std::cout << "Intern creates " << form->getName() << std::endl;
        delete form;

        form = intern.makeForm("presidential pardon", "Target2");
        std::cout << "Intern creates " << form->getName() << std::endl;
        delete form;

        std::cout << "------- CATCHED EXCEPTION FORM ------" << std::endl;
        form = intern.makeForm("nonexistent form", "Target3");
        delete form;
        
    } catch (const Intern::FormDoesntExist &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

