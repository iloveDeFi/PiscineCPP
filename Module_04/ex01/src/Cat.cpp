/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:05:58 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 16:07:11 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : type("Cat") {
	std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "A nice " << this->type << " is copied." << std::endl;
	*this = other;

}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Cat::operator=(other);
		this->type = other.type;
	}
	std::cout << "A nice " << this->type << "assigned." << std::endl;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "A nice " << this->type << " made a meow meow" << std::endl;
}

std::string Cat::getType(void) const {
	std::cout << "GetType function called for a :" << std::endl;
	return this->type;
}
