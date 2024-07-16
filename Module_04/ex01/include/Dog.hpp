/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:32:53 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 15:52:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal {
	protected: 
		std::string type;
	public: 
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif