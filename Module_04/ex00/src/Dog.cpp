/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 10:27:41 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

// Default Constructor
Dog::Dog(void) : Animal("Dog") {
	std::cout << this->type << " constructor called." << std::endl;
}

// Parametric constructor
Dog::Dog(const std::string &type) : Animal(type) {
    std::cout << "Dog parametric constructor called." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "A cool " << this->type << " is copied today." << std::endl;
}

// Assignment operator
Dog& Dog::operator=(const Dog &other) {
    if (this != &other) {
		this->type = other.type;
    }
    std::cout << "A cool " << this->type << " copy assigned." << std::endl;
    return *this;
}

// Destructor virtual
Dog::~Dog(void) {
	std::cout << this->type << " destructor called." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "A cool " << this->type << " made a wouf wouf" << std::endl;
}

std::string Dog::getType(void) const {
	std::cout << "This beast is a : " << std::endl;
	return this->type;
}