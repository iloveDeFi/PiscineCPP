/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:26 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 23:19:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : type("default") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMateria parametric constructor called" << std::endl;
}

// Copy constructor 
AMateria::AMateria(const AMateria &other) : type(other.type) {
	 std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignment operator
AMateria& AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		// type is const, wont change after init
		std::cout << "AMateria copy assignment operator called" << std::endl;
	}
	return *this;
}

// Destructor
AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

// Methods, setters, getters
std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "using materia on " << target.getName()
		<< " *" << std::endl;
}
