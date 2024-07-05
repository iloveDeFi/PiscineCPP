/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:19 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// New && Delete : Your Zombies must be destroyed at the appro-
// priate time (when they are not needed anymore). 
// They must be allocated on the stack or the heap depending on its use: 
// sometimes it’s appropriate to have them on the stack,
// at other times the heap may a better choice.

#include "Zombie.hpp"

// my constructor by default
Zombie::Zombie( void ) {
	std::cout << "Ow! A new Zombaby called " << this->_name << " is born." << std::endl;
}


Zombie::Zombie( void ) {

}

// my destructor
Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " died." << std::endl;
}

// my setters
void Zombie::setName(const std::string& name) {
	_name = name;
}

// my getters
std::string Zombie::getName( void ) const {
	return _name;
}

// other methods = member function
std::string announce( void ) {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}