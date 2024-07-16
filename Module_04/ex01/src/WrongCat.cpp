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
#include <iostream>
#include <string>

WrongCat::WrongCat(void) : type("WrongCat") {
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "A nice " << this->type << " is copied." << std::endl;
	*this = other;

}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongCat::operator=(other);
		this->type = other.type;
	}
	std::cout << "A nice " << this->type << "assigned." << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "A nice " << this->type << " made a meow meow" << std::endl;
}

std::string WrongCat::getType(void) const {
	std::cout << "GetType function called for a :" << std::endl;
	return this->type;
}
