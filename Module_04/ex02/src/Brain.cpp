/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:44:43 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:43:32 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

// Default constructor
Brain::Brain(void) {
	std::cout << "Brain constructor called." << std::endl;
}

// Copy construcotr
Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

// Copy assignement operator
Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
		for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
	}
    std::cout << "Brain assignment operator called." << std::endl;
    return *this;
}

// Destructor
Brain::~Brain(void) {
	std::cout << "Brain destructor called." << std::endl;
}
