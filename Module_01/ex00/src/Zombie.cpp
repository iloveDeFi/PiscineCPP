/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:19 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 14:53:41 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// New && Delete : Your Zombies must be destroyed at the appro-
// priate time (when they are not needed anymore). 
// They must be allocated on the stack or the heap depending on its use: 
// sometimes it’s appropriate to have them on the stack,
// at other times the heap may a better choice.

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << " Constructor called for: " << this->_name<< std::endl;
}

Zombie::~Zombie(void) {
	std::cout << " Zombie " << this->_name << " died." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
