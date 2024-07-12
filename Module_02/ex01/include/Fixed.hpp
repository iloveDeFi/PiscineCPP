/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:42:20 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/12 13:22:08 by bat              ###   ########.fr       */
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
        static const int _bits = 8;

    public:
        // A default constructor (can be in private if needed)
        Fixed(void);

        // Const INT parametric constructor
        Fixed(int const integer);

        // Const FLOAT parametric constructor
        Fixed(float const floatingNumber);

        // A copy constructor to copy class instance
        Fixed(const Fixed &other);

        // A copy assignment operator overload.
        Fixed& operator=(const Fixed &other);

         // Destructor (will need virtual later)
        ~Fixed(void);

        // Methods, setters, getters
        void setRawBits(int const raw);
        int getRawBits(void) const;

        float toFloat(void) const;
        int toInt(void) const;

        // Surcharge de l'opérateur <<
        friend std::ostream&   operator<<(std::ostream &os,
            const Fixed &fixed);
};

// Redirect stream on standard output good practice
std::ostream&   operator<<(std::ostream &os, const Fixed &fixed);

#endif