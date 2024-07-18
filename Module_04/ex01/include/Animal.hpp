/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:27:18 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:42:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected: 
		std::string type;
	public:
		// Default constructor
		Animal(void);
		// Parametric constructor
    	Animal(const std::string &type);
		// Copy constructor
		Animal(const Animal &other);
		// Copy assignement operator
		Animal &operator=(const Animal &other);
		// Destructor
		virtual ~Animal(void);
		// Methods, getters, setters
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif
