/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:58:20 by bat               #+#    #+#             */
/*   Updated: 2024/07/22 14:42:29 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "DEfault constructor called." << std::endl;
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "Param construcor called." << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor called." << std::endl;
}

// Copy assignement operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
		std::cout << "Bureaucrat copy assigned properly." << std::endl;
	}
	return *this;
}

// Destructor
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
	if (this->_grade++ > 150)
		throw GradeTooHighException();
	this->_grade++;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade-- < 1)
		throw GradeTooLowException();
	this->_grade--;
}

// Surcharge de l'opérateur << pour l'affichage
std::ostream& operator<<(std::ostream &o, Bureaucrat const &other) {
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}