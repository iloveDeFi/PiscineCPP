/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:31:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:52:05 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal {
	private:
    	Brain* _brain;
	protected: 
		std::string type;
	public: 
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif