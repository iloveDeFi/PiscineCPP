/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:13:41 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 16:10:32 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	_name;

	public:
		// constructor
		Zombie(std::string name);
		// destructor
		~Zombie(void);
		// Methods : setters and getters
		void	announce(void);
};

/* Creates zombie, name it, and return it 
so you can use it outside of the function scope. */
Zombie	*newZombie(std::string name);

/* It creates a zombie, name it, and the zombie announces itself. */
void	randomChump(std::string name);

#endif