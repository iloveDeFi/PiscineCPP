/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:26 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 15:43:02 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructor by default
AMateria::AMateria(void) : type(type) {
	std::cout << "AMateria default constructor called" << std::endl;
}

// Parametric constructor
// AMateria::AMateria(const std::string &type) {
// 	std::cout << "AMateria parametric constructor called" << std::endl;
// }

// Copy constructor 
AMateria::AMateria(const AMateria &other) : type(other.type) {
	 std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignement operator
AMateria::AMateria &operator=(const AMateria &other) {
	std::cout << "AMateria copy assignement operator called" << std::endl;
	if (this != other)
		this->type = other.type;
	return *this;
}

// Destructor
AMateria::~AMateria(void) {
	// delete _type;
	std::cout << "AMateria destructor called" << std::endl;
}

// Methods, setters, getters

std::string const & getType() const {
	return this->type;
}

virtual AMateria* clone() const {

}

void AMateria::use(ICharacter& target) {
    std::cout << "using materia on " << target.getName() << " *" << std::endl;
}
