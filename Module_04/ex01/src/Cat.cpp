/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:05:58 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:49:58 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

// Default constructor
Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat constructor called." << std::endl;
}

// Parametric constructor
Cat::Cat(const std::string &type) : Animal(type), _brain(new Brain()) {
    std::cout << "Cat parametric constructor called." << std::endl;
}

// Copy construcotr
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "A nice " << this->type << " is copied today." << std::endl;
}

// Copy assignement operator
Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
		this->type = other.type;
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
}

// Destructor
Cat::~Cat(void) {
	delete _brain;
	std::cout << this->type << "destructor called." << std::endl;
}

// Methods, getters, setters:
void Cat::makeSound(void) const {
	std::cout << "A nice " << this->type << " made a meow meow" << std::endl;
}

std::string Cat::getType(void) const {
	std::cout << "This creature is a :" << std::endl;
	return this->type;
}
