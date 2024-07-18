/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 13:38:55 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

// Default Constructor
Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
	std::cout << this->type << " constructor called." << std::endl;
}

// Parametric constructor
Dog::Dog(const std::string &type) : Animal(type), _brain(new Brain()) {
    std::cout << "Dog parametric constructor called." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << this->type << " copied with copy constructor!" << std::endl;
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
	delete _brain;
	std::cout << this->type << " destructor called." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "A cool " << this->type << " made a wouf wouf" << std::endl;
}

std::string Dog::getType(void) const {
	std::cout << "This beast is a : " << std::endl;
	return this->type;
}