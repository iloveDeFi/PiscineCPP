/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:54:01 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 16:58:06 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {}
Karen::~Karen(void) {}

// Private methods
void Karen::debug(void) {
    std::cout << "I love to get extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
                 "I just love it!" << std::endl;
}

void Karen::info(void) {
    std::cout << "I cannot believe adding extra bacon cost more money "
                 "You don’t put enough! If you did I would not have to "
                 "ask for it!" << std::endl;
}

void Karen::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free."
                 "I’ve been coming here for years and you just started "
                 "working here last month." << std::endl; 
}

void Karen::error(void) {
    std::cout << "Unacceptable, I want to speak to the manager now."
        << std::endl;
}

// Public method
void Karen::complain(const std::string level) {
    // my array of pointers to member functions
    void (Karen::*complaints[])(void) = {
        &Karen::debug,
        &Karen::info,
        &Karen::warning,
        &Karen::error
    };

    // my string array
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    // Loop to match level and call my funct
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*complaints[i])();
            return;
        }
    }
    std::cout << "Invalid complaint level." << std::endl;
}
