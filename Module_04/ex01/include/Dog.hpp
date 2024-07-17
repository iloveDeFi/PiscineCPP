/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:32:53 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:50:17 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"
class Dog : public Animal {
	private:
    	Brain* _brain;
	protected: 
		std::string type;
	public: 
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif