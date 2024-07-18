/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:10:35 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 08:14:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongBrain.hpp"
#include <string>
#include <iostream>

// Default constructor
WrongBrain::WrongBrain(void) : type("WrongBrain") {
	std::cout << "WrongBrain constructor called" << std::endl;
}

// Copy constructor
WrongBrain::WrongBrain(const WrongBrain &other) {
	std::cout << "WrongBrain obj. copied properly." << std::endl;
	*this = other;
}

// Assignement operator
WrongBrain& WrongBrain::operator=(const WrongBrain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
		this->type = other.type;
    }
	std::cout << "WrongBrain content assigned to another obj." << std::endl;
    return *this;
}

// Destructor
WrongBrain::~WrongBrain(void) {
	std::cout << "Brain destructor called properly." << std::endl;
}

#endif