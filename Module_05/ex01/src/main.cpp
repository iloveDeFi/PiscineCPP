/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/23 11:52:27 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "----------EX01 TEST----------" << std::endl;

    // Test pour vérifier les exceptions lors de la création des objets Form
    try {
        Bureaucrat samsam("SamSam", 50);

        std::cout << "----Tests Grade to high < 1----" << std::endl;
        try {
            Form formA("FormA", 45, 100);  // Valide
            std::cout << formA << std::endl;

            // Test avec un grade trop élevé pour signer
            Form formB("FormB", 0, 100);
        } catch (const std::exception &e) {
            std::cerr << "Exception during form creation: " << e.what() << std::endl;
        }

        try {
            // Test avec un grade trop bas pour exécuter
            Form formC("FormC", 100, -1);
        } catch (const std::exception &e) {
            std::cerr << "Exception during form creation: " << e.what() << std::endl;
        }

        try {
            // Test avec un grade trop élevé pour signer
            Form formD("FormD", 152, 20);
        } catch (const std::exception &e) {
            std::cerr << "Exception during form creation: " << e.what() << std::endl;
        }

        try {
            // Test avec un grade trop bas pour exécuter
            Form formE("FormE", 20, 153);
        } catch (const std::exception &e) {
            std::cerr << "Exception during form creation: " << e.what() << std::endl;
        }

        // Test de la méthode signForm
        try {
            Form formF("FormF", 45, 100);
            samsam.signForm(formF);  // Devrait réussir
            std::cout << formF << std::endl;

            // Test d'un form qui ne peut pas être signé
            Form formG("FormG", 30, 100); // Le grade de Samsam est 50
            samsam.signForm(formG);  // Devrait échouer
            std::cout << formG << std::endl;

        } catch (const std::exception &e) {
            std::cerr << "Exception during form signing: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
