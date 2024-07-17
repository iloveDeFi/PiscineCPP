/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:27:18 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:15:29 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected: 
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;
		virtual std::string getType(void) const;
};

#endif
