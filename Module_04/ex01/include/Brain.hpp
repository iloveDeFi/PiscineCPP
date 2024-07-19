/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:44:54 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 23:31:42 by bat              ###   ########.fr       */
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
};

#endif