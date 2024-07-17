/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:45:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 21:11:06 by bat              ###   ########.fr       */
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
		std::string _ideas[100];
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		virtual ~Brain(void);
		virtual void makeSound(void) const;
		virtual std::string getType(void) const;
};

#endif
