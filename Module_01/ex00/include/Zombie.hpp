/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:13:41 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/05 14:00:25 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>

// USING CANONICAL FORM TO LEARN
class Zombie {
	private:
		std::string _name;

	public:
	// Constructors
		Zombie( void );
		Zombie( void ); // with parameters
		// make 
		~Zombie( void );

	// Methods : setters and getters
	void setName(const std::string& name);
	std::string getName( void ) const;
	std::string announce( void ) const;
};

#endif