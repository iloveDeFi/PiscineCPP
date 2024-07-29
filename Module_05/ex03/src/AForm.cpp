/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:53:55 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/25 14:32:33 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute) {
			if (_gradeToSign < 1 || _gradeToExecute < 1)
        		throw GradeTooHighException();
    		if (_gradeToSign > 150 || _gradeToExecute > 150)
        		throw GradeTooLowException();
			std::cout << "Parametric constructor AForm called" << std::endl;
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
			std::cout << "Copy constructor AForm called." << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	std::cout << "Copy assignment operator AForm called" << std::endl;
	return *this;
}

AForm::~AForm(void) {
	std::cout << "Destructor AForm called." << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &o, AForm const &aform) {
    o << "AForm " << aform.getName() << " requires grade " << aform.getGradeToSign() 
      << " to sign and grade " << aform.getGradeToExecute() << " to execute. Signed status: "
      << (aform.isSigned() ? "Signed" : "Not signed");
    return o;
}
