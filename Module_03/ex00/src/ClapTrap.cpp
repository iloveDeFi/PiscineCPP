/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:20 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 10:40:23 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// ClapTrap object needs energy and health to take action

// Default constructor
ClapTrap::ClapTrap(void) :
	_name("default"), 
	_health(10),
	_energy(10),
	_damage(0) {
	std::cout << "ClapTrap " << _name << " default constructed." << std::endl;
}

// Parametric constructor with my initializer list
ClapTrap::ClapTrap(std::string name) :
    _name(name), 
    _health(10),
    _energy(10),
    _damage(0) {
    std::cout << "ClapTrap " << _name << " param constructed." << std::endl;
}

// Copy constructor &other = src
ClapTrap::ClapTrap(const ClapTrap &other) :
     _name(other._name),
     _health(other._health),
     _energy(other._energy),
     _damage(other._damage) {
    std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

// Overloard assignement operator 
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _health = other._health;
        _energy = other._energy;
        _damage = other._damage;
    }
    std::cout << "ClapTrap " << _name << " assigned by = operator."
        << std::endl;
    return *this;
}


// Target lose <attack damage>
// Cost 1 energy point
void ClapTrap::attack(const std::string &target) {
    if (this->_energy == 0 || this->_health == 0) {
        std::cout << this->_name << " cant attack, no more battery or health."
            << std::endl;
        return;
    }
    this->_energy -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_health -= amount;
    if (this->_health < 0)
        this->_health = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
        << " points of damage" << std::endl;
}

// Repair <amount> of hit points back
// Cost 1 energy point
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy == 0 || this->_health == 0) {
        std::cout << this->_name << " cant repair, no more battery or health."
            << std::endl;
        return;
    }
    this->_energy -= 1;
    this->_health += amount;
    std::cout << "ClapTrap " << _name << " repaired himself of "
        << amount << " energy points!" << std::endl;
}

void ClapTrap::displayInfos() const {
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Health: " << this->_health << std::endl;
    std::cout << "Energy: " << this->_energy << std::endl;
    std::cout << "Damage: " << this->_damage << std::endl;
}