/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:45:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 07:38:27 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {		
	protected: 
		std::string type;
		
	public:
		std::string ideas[100];
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		virtual ~Brain(void);
		// virtual void makeSound(void) const;
		// virtual std::string getType(void) const;
};

#endif
