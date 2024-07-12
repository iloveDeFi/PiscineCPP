/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:02:54 by bat               #+#    #+#             */
/*   Updated: 2024/07/12 11:20:43 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor 
Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

// Copy constructor object (init object dst from an object src)
// Sample obj2 = obj1; Copied object with same values and states as src obj. 
Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignement operator = copie content to another object from same class
// Sample obj2 = obj1; update object state avoiding recreating targeted object
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
    return;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Methods get and set
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}
