/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:32:53 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 10:46:08 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	public: 
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif