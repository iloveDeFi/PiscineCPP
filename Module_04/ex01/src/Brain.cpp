/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:39:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 14:13:48 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Brain.hpp"

// Default constructor
Brain::Brain(void) {
	std::cout << "Brain constructor called on " << this->type << std::endl;
}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << "Brain obj. copied properly." << std::endl;
	*this = other;
}

// Assignement operator
Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        Brain::operator=(other);
        this->type = other.type;
        this->_ideas[100] = other._ideas[100];
    }
	std::cout << "Brain assigned to another obj." << std::endl;
	return *this;
}

// Destructor
Brain::~Brain(void) {
	std::cout << "Brain destructor called with delete." << std::endl;
}