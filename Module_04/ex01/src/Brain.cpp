/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:39:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 17:15:45 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Brain.hpp"

// Default constructor
Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << "Brain obj. copied properly." << std::endl;
}

// Assignement operator
Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assigned to another obj." << std::endl;
}

// Destructor
Brain::~Brain(void) {
	std::cout << "Brain destructor called with delete." << std::endl;
}