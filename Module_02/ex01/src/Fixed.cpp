/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:47:16 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/12 11:46:50 by bat              ###   ########.fr       */
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
Fixed::Fixed(int const integer) {
    std::cout << "Int param constructor called" << std::endl;
    // to  in fixed virgule
    this->_value = integer << this->_bits;
}

// Parametric constructor with float
Fixed::Fixed(float const num) {
    std::cout << "Float param constructor called" << std::endl;
    // conversion in fixed virgule
    this->_value = roundf(num * (1 << _bits));
}

// Copy constructor 
Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignement operator
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Methods get and set
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::toInt() const {
    return this->_value >> _bits;
}

float Fixed::toFloat(void) const {
    // divison to get floating part
    return static_cast<float>(_value) / (1 << _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}