/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:08:27 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 13:08:50 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongBrain.hpp"
#include <iostream>
#include <string>

// Default constructor
WrongBrain::WrongBrain(void) {
	std::cout << "WrongBrain constructor called." << std::endl;
}

// Copy construcotr
WrongBrain::WrongBrain(const WrongBrain &other) {
	std::cout << "WrongBrain copy constructor called." << std::endl;
	for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

// Copy assignement operator
WrongBrain &WrongBrain::operator=(const WrongBrain &other) {
    if (this != &other) {
		for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
	}
    std::cout << "WrongBrain assignment operator called." << std::endl;
    return *this;
}

// Destructor
WrongBrain::~WrongBrain(void) {
	std::cout << "WrongBrain destructor called." << std::endl;
}
