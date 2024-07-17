/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:13:56 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 13:15:56 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name << " is awake!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_health = 100;
    this->_energy = 100;
    this->_damage = 30;
    std::cout << "FragTrap " << this->_name << " is readyyyyyy!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->_name << " is copied!" << std::endl;
    *this = other;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " annihilated!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_health = other._health;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "FragTrap " << this->_name << " assigned!" << std::endl;
    return *this;
}

void FragTrap::attack(std::string const &target) {
    std::cout << "FragTrap " << this->_name << " attacks " << target
              << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " *CLAP* just did a high-five!!" << std::endl;
}
