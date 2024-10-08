/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:02:57 by bat               #+#    #+#             */
/*   Updated: 2024/07/16 09:21:06 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// Orthodox Canonical Form that represents a fixed-point number
// Need 4 elements :
// - Default constructor
// - Copy constructor (create copie of another object)
// - Copy assignement operator = (copie content of an object in another)
// - Destructor with virtual
class Fixed {
    private:
        int _value;
        static const int _bits;

    public:
        // A default constructor (can be in private if needed)
        Fixed(void);

        // A copy constructor to copy class instance
        Fixed(const Fixed &other);

        // A copy assignment operator overload.
        Fixed& operator=(const Fixed &other);

         // Destructor (will need virtual later)
        ~Fixed(void);

        // Methods, setters, getters
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

// Redirect stream on standard output good practice
std::ostream&   operator<<(std::ostream& o, const Fixed& i);

#endif