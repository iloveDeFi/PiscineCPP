/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:43:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 07:56:58 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <string>

class WrongCat : public WrongAnimal {
	private:
    	Brain* _brain;
	protected: 
		std::string type;
	public: 
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		virtual ~WrongCat(void);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif