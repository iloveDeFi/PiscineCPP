/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:34:18 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 15:57:07 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

// 
Ice::Ice(Ice const &other) : AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
}

// Copy assignement operator
Ice& Ice::operator=(Ice const &other) {
	std::cout << "Ice copy assignement operator called" << std::endl;
    if (this != &other) {
		this-> ?? = ??;
    }
    return *this;
}

// Destructor
Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
