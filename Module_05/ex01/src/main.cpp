/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/22 14:49:39 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

int main() {
	std::cout << "----------LOW TEST----------" << std::endl;
    try {
        Bureaucrat bob("Bob", 151);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "----------HIGH TEST----------" << std::endl;
	try {
        Bureaucrat bob("Bricole", -4);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "----------GOOD TEST----------" << std::endl;
	try {
        Bureaucrat bob("Tasseur", 10);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
