/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:03:34 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 13:46:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructor by default
MateriaSource::MateriaSource(void) : type(type) {
	std::cout << "MateriaSource default constructor called" << std::endl;
}

// Parametric constructor
MateriaSource::MateriaSource(const std::string &type) : type(type) {
	std::cout << "MateriaSource parametric constructor called" << std::endl;
}

// Copy constructor 
MateriaSource::MateriaSource(const MateriaSource &other) : type(other) {
	 std::cout << "MateriaSource copy constructor called" << std::endl;
}

// Copy assignement operator
MateriaSource::MateriaSource &operator=(const MateriaSource &other) {
	std::cout << "MateriaSource copy assignement operator called" << std::endl;
	if (this != other)
		this->type = other.type;
	return *this;
}

// Destructor
MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called" << std::endl;
}

// Methods, setters, getters
std::string const & getType() const {
	return this->type;
}

virtual MateriaSource* clone() const {

}

void MateriaSource::use(ICharacter& target) {
    std::cout << "using materia on " << target.getName()
		<< " *" << std::endl;
}
