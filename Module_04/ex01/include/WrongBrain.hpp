/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:07:34 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 13:08:01 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGBRAIN_HPP
# define WRONGBRAIN_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class WrongBrain {
	public: 
		std::string ideas[100];
		WrongBrain(void);
		WrongBrain(const WrongBrain &other);
		WrongBrain &operator=(const WrongBrain &other);
		virtual ~WrongBrain(void);
		// void printIdeasCount() const;
};

#endif