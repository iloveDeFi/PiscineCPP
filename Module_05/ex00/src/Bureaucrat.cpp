/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:20 by bat               #+#    #+#             */
/*   Updated: 2024/07/29 11:06:37 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "Construcor called properly with param." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
		std::cout << "Bureaucrat copy assigned properly." << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    ++_grade;
}

std::ostream& operator<<(std::ostream &o, Bureaucrat const &other) {
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}