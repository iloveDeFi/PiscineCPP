/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:27 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 16:11:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class AMateria
{
	protected:
		std::string type;
		
	public:
		// Constructor by default
		AMateria(void);
		// Parametric constructor
		// AMateria(const std::string &type);
		// Copy constructor 
		AMateria(const AMateria &other);
		// Copy assignement operator
		AMateria &operator=(const AMateria &other);
		// Destructor
		virtual ~AMateria(void);
		// Methods, setters, getters
		std::string const & getType() const;
		// Gonna implement my PURE virtual method in derived classes
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		
};

#endif