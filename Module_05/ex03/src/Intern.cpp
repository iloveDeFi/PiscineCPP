/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:20 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/29 15:20:01 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
    (void)intern;
}

Intern& Intern::operator=(const Intern &intern) {
    (void)intern;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeSCF(std::string target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRRF(std::string target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePPF(std::string target) const {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string formName, const std::string &target) const {
    try {
        if (formName == "shrubbery creation") {
            return makeSCF(target);
        } else if (formName == "robotomy request") {
            return makeRRF(target);
        } else if (formName == "presidential pardon") {
            return makePPF(target);
        } else {
            throw FormDoesntExist();
        }
    } catch (const FormDoesntExist &e) {
        // std::cerr << "Exception caught: " << e.what() << std::endl;
        throw;
    }
}