/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:50:23 by bat               #+#    #+#             */
/*   Updated: 2024/07/12 18:02:52 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Static member initialization
const int Fixed::_bits = 8; // 8 bits for the fractional part

// Default constructor
Fixed::Fixed(void) : _value(0) {
}

// Parametric constructor with int
Fixed::Fixed(int const integer) {
    this->_value = integer << this->_bits;
}

// Function to round float values (alternative to roundf for C++98)
static int roundToNearestInt(float num) {
    return (num >= 0) ? static_cast<int>(num + 0.5f) : static_cast<int>(num - 0.5f);
}

// Parametric constructor with float
Fixed::Fixed(float const num) {
    this->_value = roundToNearestInt(num * (1 << this->_bits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value) {
}

// Destructor
Fixed::~Fixed(void) {
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Increment and decrement operators
Fixed& Fixed::operator++(void) {
    ++this->_value; // Increment by the smallest unit
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--(void) {
    --this->_value; // Decrement by the smallest unit
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    int64_t mul = static_cast<int64_t>(this->_value) * static_cast<int64_t>(other.getRawBits());
    result.setRawBits(static_cast<int>(mul >> this->_bits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other.getRawBits() != 0) {
        int64_t div = (static_cast<int64_t>(this->_value) << this->_bits) / other.getRawBits();
        result.setRawBits(static_cast<int>(div));
    } else {
        std::cerr << "Error: Division by zero" << std::endl;
    }
    return result;
}

// Min and max functions
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

// Getter and setter for raw bits
int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Conversion functions
int Fixed::toInt(void) const {
    return this->_value >> this->_bits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_value) / (1 << this->_bits);
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
