/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:31:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:44:55 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
	private:
		Brain* _brain;
	public: 
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif