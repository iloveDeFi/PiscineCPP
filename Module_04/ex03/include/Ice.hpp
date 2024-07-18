/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:35:11 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 15:54:26 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria {
	public:
		// Constructor by default
		Ice(void);
		// // Parametric constructor
		// Ice(const std::string &type);
		// Copy constructor 
		Ice(const Ice &other);
		// Copy assignement operator
		Ice &operator=(const Ice &other);
		// Destructor
		virtual ~Ice(void);
		// Methods, setters, getters
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif
