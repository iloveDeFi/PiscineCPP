/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:39:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:14:55 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Brain.hpp"

// Default constructor
Brain::Brain(void) : type("Brain") {
	std::cout << "Brain constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << "Brain obj. copied properly." << std::endl;
	*this = other;
}

// Assignement operator
Brain& Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
		this->type = other.type;
    }
	std::cout << "Brain content assigned to another obj." << std::endl;
    return *this;
}

// Destructor
Brain::~Brain(void) {
	std::cout << "Brain destructor called properly." << std::endl;
}