/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:32:53 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:45:09 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
	private:
		Brain* _brain;
	public: 
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif