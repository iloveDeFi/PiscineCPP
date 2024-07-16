/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:28:13 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 15:28:09 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal " << this->type << " is copied." << std::endl;
	*this = other;

}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
	}
	std::cout << "Animal " << this->type << "assigned." << std::endl;
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "An animal made a strange noise." << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}
