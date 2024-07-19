/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:37:21 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 11:22:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(Cure const &other) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* shoots an Cure bolt at " << target.getName()
		<< " *" << std::endl;
}
