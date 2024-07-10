/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:02:57 by bat               #+#    #+#             */
/*   Updated: 2024/07/10 11:44:23 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// Orthodox Canonical Form that represents a fixed-point number
// Need 4 elements :
// - Default constructor
// - Copy constructor (new instance created)
// - Assignement operator = (update current instance)
// - Destructor with virtual
class Fixed {
    private:
        int _fixedPointValue;
        static const int _bits = 8;

    public:
        // A default constructor (can be in private if needed)
        Fixed(void);
        // Parametric constructor instead of my setter method
        Fixed(int fixedPointValue, const int bits);
        // A copy constructor to copy class instance
        Fixed(const Fixed& other);
         // Destructor (will need virtual later)
        ~Fixed(void);
        
        // A copy assignment operator overload.
        Fixed& operator=(const Fixed& rhs);
        // Methods, setters, getters
        int getRawBits() const;
};

// Redirect stream on standard output good practice
std::ostream&   operator<<(std::ostream& o, const Fixed& i);

#endif