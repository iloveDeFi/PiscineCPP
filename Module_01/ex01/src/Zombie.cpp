/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:00:59 by bat               #+#    #+#             */
/*   Updated: 2024/07/08 16:49:26 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Prefer Initialization list > body assignement with this->

// Default constructor
Zombie::Zombie(void) : _name("Unnamed") {
    std::cout << "Unnamed zombie is created by constructor call." << std::endl;
}

// My construct with parameter
Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie named " << _name << " is alive."<< std::endl;
}

// My destructor
Zombie::~Zombie(void) {
    std::cout << "Zombie named " << _name << " deleted." << std::endl;
}

// Methods setters and getters
void	Zombie::announce()
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

void    Zombie::setName(std::string name) {
    _name = name;
}
