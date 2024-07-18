/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:28:13 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 14:03:27 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

// Default constructor
Animal::Animal(void) : type("Animal") {
	std::cout << "Animal constructor called." << std::endl;
}

// Parametric constructor
Animal::Animal(const std::string &type) : type(type) {
    std::cout << "Animal parametric constructor called." << std::endl;
}

// Coopy constructor
Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal " << this->type << " is copied." << std::endl;
}

// Copy assignement operator
Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "Animal " << this->type << " assigned." << std::endl;
	return *this;
}

// Destructor 
Animal::~Animal(void) {
	std::cout << "Animal destructor called." << std::endl;
}

// Methods, getters, setters:
void Animal::makeSound(void) const {
	std::cout << "An animal " << this->type << " made a strange noise."
		<< std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}
