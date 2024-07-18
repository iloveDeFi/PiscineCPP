/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:43:46 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 13:10:05 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "WrongBrain.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal {
	private:
		WrongBrain* _wrongBrain;
	public: 
		WrongCat(void);
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		virtual ~WrongCat(void);
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif