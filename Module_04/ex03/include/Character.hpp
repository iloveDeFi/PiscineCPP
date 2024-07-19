/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:51:41 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 16:32:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*inventory[4];
	public:
		// Canonical form
		Character(void);
		Character(std::string const &name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		virtual ~Character(void);
		// Interface contract
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		// Methods
		virtual void initInventory(void);
};

#endif

