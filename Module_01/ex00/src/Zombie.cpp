/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:19 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/05 14:07:36 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

std::string Zombie::_name = ;

// my constructor by default
Zombie::Zombie( void )
	: _name("") {
}


Zombie::Zombie( void ) {

}

// my destructor
Zombie::~Zombie( void ) {
	
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