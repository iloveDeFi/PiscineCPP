/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:50:08 by bat               #+#    #+#             */
/*   Updated: 2024/07/16 10:51:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _bits;

    public:
        // A default constructor (can be in private if needed)
        Fixed(void);

        // Const INT parametric constructor
        Fixed(int const integer);

        // Const FLOAT parametric constructor
        Fixed(float const floatingNumber);

        // A copy constructor to copy class instance
        Fixed(const Fixed& other);

        // Destructor (will need virtual later)
        ~Fixed(void);

        // Overloaded Operators
        // Assignment operators
        Fixed& operator=(const Fixed& other); // Assignement operator
        Fixed& operator++(void);   // Pré-incrémentation operator
        Fixed operator++(int value); // Post-incrémentation operator
        Fixed& operator--(void);   // Pré-décrémentation operator
        Fixed operator--(int value); // Post-décrémentation operator
        
        // Compare operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Arithetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Static functions min et max
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        // Methods, setters, getters
        void setRawBits(int const raw);
        int getRawBits(void) const;

        float toFloat(void) const;
        int toInt(void) const;
};

// Overload operator <<        
std::ostream&   operator<<(std::ostream &os,
            const Fixed &fixed);

#endif