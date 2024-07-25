/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/25 14:50:58 by bbessard         ###   ########.fr       */
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

int main() {
    std::cout << "----------EX02 TEST EXECUTE----------" << std::endl;

    Bureaucrat bureaucrat("Alex", 30);

    std::cout << "-----Test ShrubberyCreationFOrm-----" << std::endl;
    try {
        ShrubberyCreationForm shrubberyForm("(A)");
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----Test RobotomyRequestForm-----" << std::endl;
    try {
        RobotomyRequestForm robotomyForm("(B)");
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----Test PresidentialPardonForm-----" << std::endl;
    try {
        PresidentialPardonForm pardonForm("(C)");
        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
