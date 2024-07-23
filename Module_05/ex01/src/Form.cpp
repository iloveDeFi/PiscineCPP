/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:53:55 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/23 11:17:21 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _gradeToSign(1),
	_gradeToExecute(1) {
		std::cout << "Default constructor Form called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute) {
			if (_gradeToSign < 1 || _gradeToExecute < 1)
        		throw GradeTooHighException();
    		if (_gradeToSign > 150 || _gradeToExecute > 150)
        		throw GradeTooLowException();
			std::cout << "Parametric constructor Form called" << std::endl;
}

Form::Form(const Form &other) 
	: _name(other._name), _isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
			std::cout << "Copy constructor Form called." << std::endl;
}

Form& Form::operator=(const Form &other) {
	if (this != &other)
	{
		// my others variables are const! no need to assign them sheesh
		_isSigned = other._isSigned;
	}
	std::cout << "Copy assignment operator Form called" << std::endl;
	return *this;
}

Form::~Form(void) {
	std::cout << "Destructor Form called." << std::endl;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream &o, Form const &form) {
    o << "Form " << form.getName() << " requires grade " << form.getGradeToSign() 
      << " to sign and grade " << form.getGradeToExecute() << " to execute. Signed status: "
      << (form.getSigned() ? "Signed" : "Not signed");
    return o;
}
