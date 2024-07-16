/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:10:29 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 16:35:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal " << this->type << " is copied." << std::endl;
	*this = other;

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	std::cout << "WrongAnimal " << this->type << "assigned." << std::endl;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal made a wrong noise." << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}
