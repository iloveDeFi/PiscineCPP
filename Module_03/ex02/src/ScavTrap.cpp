/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:55:20 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 13:15:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_health = 100;
    this->_energy = 50;
    this->_damage = 20;
    std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->_name << " is copied!" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_health = other._health;
        this->_energy = other._energy;
        this->_damage = other._damage;
    }
    std::cout << "ScavTrap " << this->_name << " assigned!" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->_energy == 0 || this->_health == 0) {
        std::cout << this->_name << " cant attack, no more battery or health."
            << std::endl;
        return;
    }
    this->_energy -= 10;
    std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
