/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:42:52 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 10:47:44 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& _type) : _type(_type) {
    std::cout << "Weapon created with type: " << _type << std::endl;
}

Weapon::~Weapon(void) {
    std::cout << "Weapon destroy by destructor." << std::endl;
}

void Weapon::setType(const std::string& newType) {
    _type = newType;
}

const std::string& Weapon::getType(void) const {
    std::cout << "weapon of type: " << _type << std::endl;
    return _type;
}
