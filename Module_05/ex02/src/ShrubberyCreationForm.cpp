/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:16:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/25 10:27:08 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        Form::operator=(src);
        _target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    checkExecutability(executor);
    std::ofstream ofs(_target + "_shrubbery");
    if (ofs) {
        ofs << "       _-_\n";
        ofs << "    /~~   ~~\\\n";
        ofs << " /~~         ~~\\\n";
        ofs << "{               }\n";
        ofs << " \\  _-     -_  /\n";
        ofs << "   ~  \\ //  ~\n";
        ofs << "_- -   | | _- _\n";
        ofs << "  _ -  | |   -_\n";
        ofs << "      // \\\n";
        ofs.close();
    } else {
        std::cerr << "Error: Could not create shrubbery file." << std::endl;
    }
}
