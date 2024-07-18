/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:10:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 16:11:13 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongBrain.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"),
	_wrongBrain(new WrongBrain()) {
		std::cout << "WrongCat constructor called." << std::endl;
}

// Parametric constructor
WrongCat::WrongCat(const std::string &type) : WrongAnimal(type),
	_wrongBrain(new WrongBrain()) {
    	std::cout << "WrongCat parametric constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "A nice " << this->type << " is copied." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "A nice " << this->type << "assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	delete _wrongBrain;
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "A nice " << this->type << " made a meow meow" << std::endl;
}

std::string WrongCat::getType(void) const {
	std::cout << "It's a strange :" << std::endl;
	return this->type;
}
