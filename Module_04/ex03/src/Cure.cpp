/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:37:21 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 15:57:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

// 
Cure::Cure(Cure const &other) : AMateria(other) {
	std::cout << "Cure copy constructor called" << std::endl;
}

// Copy assignement operator
Cure& Cure::operator=(Cure const &other) {
	std::cout << "Cure copy assignement operator called" << std::endl;
    if (this != &other) {
		this-> ?? = ??;
    }
    return *this;
}

// Destructor
Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}
