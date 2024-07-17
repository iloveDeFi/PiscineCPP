/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 20:41:50 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : _brain(new Brain()), type("Dog") {
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Dog copied!" << std::endl;
}

// Opérateur d'affectation
Dog& Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other); // Copier les attributs de la classe de base
        delete _brain; // Libérer la mémoire actuelle
        _brain = new Brain(*other._brain); // Allouer et copier
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "A cool " << this->type << " made a wouf wouf" << std::endl;
}

std::string Dog::getType(void) const {
	std::cout << "GetType function called for a : " << std::endl;
	return this->type;
}
