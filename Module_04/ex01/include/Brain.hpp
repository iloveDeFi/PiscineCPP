/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:44:54 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:30:06 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Brain {
	public: 
		std::string ideas[100];
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		virtual ~Brain(void);
		void printIdeasCount() const;
};

#endif