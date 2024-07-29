/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:27 by bat               #+#    #+#             */
/*   Updated: 2024/07/29 11:00:28 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

int main() {
	std::cout << "----------LOW TEST----------" << std::endl;
    try {
        Bureaucrat a1("Bob", 151);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << "----------HIGH TEST----------" << std::endl;
	try {
        Bureaucrat a2("Bricole", -4);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--OPERATOR OVERLOADING (GETTERS) --" << std::endl;
    Bureaucrat b1("Kangoo", 1);
    Bureaucrat b2("Junior", 2);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "----------INCREMENT + - TEST----------" << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;
    b2.incrementGrade();
    std::cout << b2 << std::endl;
    
    std::cout << "----------INCREMENT ERROR----------" << std::endl;
    try {
        b2.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
	std::cout << "----------NORMAL TEST----------" << std::endl;
	try {
        Bureaucrat bob("Tasseur", 10);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}