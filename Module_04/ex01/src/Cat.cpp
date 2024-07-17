/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:05:58 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:59:06 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : _brain(new Brain()), type("Cat") {
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Cat copied with copy constructor!" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
        *_brain = *other._brain;
    }
	std::cout << "A nice " << this->type << "assigned." << std::endl;
	this->_brain = new Brain(*other._brain);
	return *this;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "A nice " << this->type << " made a meow meow" << std::endl;
}

std::string Cat::getType(void) const {
	std::cout << "GetType function called for a :" << std::endl;
	return this->type;
}
