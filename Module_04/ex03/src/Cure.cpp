/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:37:21 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 23:21:51 by bat              ###   ########.fr       */
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
	std::cout << "Assigned from " << other.getType() << std::endl;
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
