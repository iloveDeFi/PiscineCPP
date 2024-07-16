/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:31:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/16 16:45:57 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal {
	private:
		const Brain *ideas;
	protected: 
		std::string type;
	public: 
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif