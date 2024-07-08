/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:13:41 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 14:50:59 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;

	public:
		// constructor
		Zombie(std::string name);
		// destructor
		~Zombie(void);
		// Methods : setters and getters
		void announce(void);
};

#endif