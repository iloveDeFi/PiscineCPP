/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:50:08 by bat               #+#    #+#             */
/*   Updated: 2024/07/12 16:35:18 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

// Orthodox Canonical Form that represents a fixed-point number
// Need 4 elements :
// - Default constructor
// - Copy constructor (new instance created)
// - Copy assignement operator = (update current instance)
// - Destructor with virtual
class Fixed {
    private:
        int _value;
        static const int _bits; // 8 bits after the virgule

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
        
        // Opérateurs de comparaison
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Opérateurs arithmétiques
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Fonctions statiques min et max
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

// Surcharge de l'opérateur <<        
std::ostream&   operator<<(std::ostream &os,
            const Fixed &fixed);

#endif