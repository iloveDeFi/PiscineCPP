/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:08:38 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 08:10:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGBRAIN_HPP
# define WRONGBRAIN_HPP

#include <string>
#include <iostream>

class WrongBrain {		
	protected: 
		std::string type;
		
	public:
		std::string ideas[100];
		WrongBrain(void);
		WrongBrain(const WrongBrain &other);
		WrongBrain &operator=(const WrongBrain &other);
		virtual ~WrongBrain(void);
};

#endif