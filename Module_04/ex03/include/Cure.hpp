/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:35:06 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 15:49:35 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>

class Cure : public AMateria {
	public:
		// Constructor by default
		Cure(void);
		// Parametric constructor
		Cure(const std::string &type);
		// Copy constructor 
		Cure(const Cure &other);
		// Copy assignement operator
		Cure &operator=(const Cure &other);
		// Destructor
		virtual ~Cure(void);
		// Methods, setters, getters
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif