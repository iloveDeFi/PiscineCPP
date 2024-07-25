/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/25 10:45:33 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardoForm.hpp"

int main() {
    std::cout << "----------EX01 TEST----------" << std::endl;

    try {
        Bureaucrat samsam("SamSam", 50);

        try {
            Bureaucrat tomtom("TomTom", 0);
        } catch (const std::exception &e) {
            std::cerr << "TomTom exception during Bureaucrat creation: " << e.what() << std::endl;
        }

        try {
            Bureaucrat leoleo("LeoLeo", 159);
        } catch (const std::exception &e) {
            std::cerr << "LeoLeo exception during Bureaucrat creation: " << e.what() << std::endl;
        }

        try {
            Form formA("FormA", 45, 100);
            std::cout << formA << std::endl;

            try {
                Form formB("FormB", 0, 100);
            } catch (const std::exception &e) {
                std::cerr << "FormB exception during form creation: " << e.what() << std::endl;
            }

            try {
                Form formC("FormC", 100, -1);
            } catch (const std::exception &e) {
                std::cerr << "FormC exception during form creation: " << e.what() << std::endl;
            }

            try {
                Form formD("FormD", 152, 20);
            } catch (const std::exception &e) {
                std::cerr << "FormD exception during form creation: " << e.what() << std::endl;
            }

            try {
                Form formE("FormE", 20, 153);
            } catch (const std::exception &e) {
                std::cerr << "FormE exception during form creation: " << e.what() << std::endl;
            }

            try {
                Form formF("FormF", 45, 100);
                samsam.signForm(formF);
                std::cout << formF << std::endl;

                Form formG("FormG", 30, 100);
                samsam.signForm(formG);
                std::cout << formG << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Exception during form signing: " << e.what() << std::endl;
            }

        } catch (const std::exception &e) {
            std::cerr << "Exception during form operations: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
