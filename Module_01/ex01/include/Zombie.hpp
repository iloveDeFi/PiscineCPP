/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:00:07 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 17:15:39 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string	_name;

    public:
        // constructors
        Zombie(void);
        Zombie(std::string name);
        // destructor
        ~Zombie(void);
        // Methods : setters and getters
        void announce(void);
        void setName(std::string name);
};

/* Creates zombie, name it, and return it 
so you can use it outside of the function scope. */
Zombie	*newZombie(std::string name);

/* It creates a zombie, name it, and the zombie announces itself. */
void	randomChump(std::string name);

Zombie*	zombieHorde(int N, std::string name);


#endif