/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 16:08:13 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : type("Dog") {
	std::cout << "Dog constructor called." << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "A cool " << this->type << " is copied." << std::endl;
	*this = other;

}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Dog::operator=(other);
		this->type = other.type;
	}
	std::cout << "A cool " << this->type << "assigned." << std::endl;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "A cool " << this->type << " made a wouf wouf" << std::endl;
}

std::string Dog::getType(void) const {
	std::cout << "GetType function called for a : " << std::endl;
	return this->type;
}