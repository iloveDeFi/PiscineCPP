/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:50:23 by bat               #+#    #+#             */
/*   Updated: 2024/07/12 16:36:35 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8; // 8 bits after the virgule

// ----------------- Canonical form -------------------------

// Default constructor 
Fixed::Fixed(void) : _value(0) {
}

// Parametric constructor with int
Fixed::Fixed(int const integer) {
    // to  in fixed virgule
    this->_value = integer << this->_bits;
}

// Parametric constructor with float
Fixed::Fixed(float const num) {
    // conversion in fixed virgule
    this->_value = roundf(num * (1 << _bits));
}

// Copy constructor 
Fixed::Fixed(const Fixed &other) : _value(other._value) {
}

// Destructor
Fixed::~Fixed(void) {
}

// Copy Assignement operator
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// ----------------- + and - operators -------------------------

Fixed& Fixed::operator++() {
    this->_value += (1 << this->_bits);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    _value -= (1 << _bits); // Décrémentation d'unité ε
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// ----------------- Comparaison operators -------------------------

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// ----------------- Arithmetics operators -------------------------

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    int64_t mul = static_cast<int64_t>(_value) * static_cast<int64_t>(other.getRawBits());
    result.setRawBits(static_cast<int>(mul >> _bits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other.getRawBits() != 0) {
        int64_t div = static_cast<int64_t>(_value) << _bits;
        result.setRawBits(static_cast<int>(div / other.getRawBits()));
    } else {
        std::cerr << "Error: Division by zero" << std::endl;
    }
    return result;
}

// ----------------- Min & Max functions -------------------------

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// ----------------- Methods, getters and setterd ----------------------

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::toInt() const {
    return this->_value >> _bits;
}

float Fixed::toFloat(void) const {
    // divison to get floating part
    return static_cast<float>(_value) / (1 << _bits);
}

// ----------------- Output overloard operator -------------------------

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}