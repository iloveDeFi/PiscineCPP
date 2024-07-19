/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:52:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 16:30:26 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>
#include <iostream>

// Default consructor 
Character::Character(void) : _name("default") {
	std::cout << "Character default constructor called" << std::endl;
	initInventory();
}

// Parametric constructor
Character::Character(std::string const & name) : _name(_name) {
	std::cout << "Character default constructor called" << std::endl;
    initInventory();
}

// Copy constructor
Character::Character(Character const &other) : _name(other._name) {
    initInventory();
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

// Assignement operator 
Character& Character::operator=(Character const &other) {
	std::cout << "Character assignement operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; ++i) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

// Default constructor
Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
	std::cout << "getName() method called for:" << std::endl;
    return this->_name;
}

// Find empty spot in inventory
void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

// Free item
void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx] = NULL;
}

// Ameteria object from inventory used
void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx]->use(target);
}

// Methods, setters, getters
void Character::initInventory(void) {
	std::cout << "Character init inventory method called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}