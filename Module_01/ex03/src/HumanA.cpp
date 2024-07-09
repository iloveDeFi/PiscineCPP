/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:31:23 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 10:49:51 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name),
    _weapon(weapon) {
    std::cout << _name << " is alive and ready to kill with his "
        << _weapon.getType() << std::endl;
}

// Destructor
HumanA::~HumanA(void) {
    std::cout << _name << " has been killed." << std::endl;
}

// Public methods
void HumanA::attack(void) const {
    std::cout << _name << " attacks with his " << _weapon.getType()
        << std::endl;
}
