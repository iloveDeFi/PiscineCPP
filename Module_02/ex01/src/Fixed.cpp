/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:47:16 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/11 19:00:18 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor 
Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Parametric constructor with int
Fixed::Fixed(const int integer) : _bits(8) {
    std::cout << "Int constructor called" << std::endl;
}

// Parametric constructor with float
Fixed::Fixed(const int integer) : _bits(8) {
    std::cout << "Float parametric constructor called" << std::endl;
}

// Copy constructor 
Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignement operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &rhs) {
        this->_value = rhs._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Methods get and set
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

float Fixed::toFloat(void) const {

}

int Fixed::toInt(void) const {
    
}