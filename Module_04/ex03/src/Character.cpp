/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:52:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 16:09:34 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>
#include <iostream>

Character::Character(std::string const & name) : name(name) {
	std::cout << "Character default constructor called" << std::endl;
    initInventory();
}

Character::Character(Character const &other) : name(other.name) {
    initInventory();
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character& Character::operator=(Character const &other) {
	std::cout << "Character assignement operator called" << std::endl;
    if (this != &other) {
        name = other.name;
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

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

void Character::initInventory() {
	std::cout << "Character init inventory method called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

std::string const & Character::getName() const {
	std::cout << "getName() method called" << std::endl;
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx]->use(target);
}
