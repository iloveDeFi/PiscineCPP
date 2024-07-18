/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:51:41 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 16:06:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

class ICharacter
{
	private:
		std::string	_name;
		AMateria* inventory[4];
    	void initInventory();
	public:
		// Default consturctor
		ICharacter(void);
		// Parametric constructor
		ICharacter(std::string const &name);
		// Copy constructor
		ICharacter(Character const &other);
		// Copy assignement operator
		INFINITY &operator=(Character const &other);
		// Destructor
		virtual ~ICharacter();
		
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif

