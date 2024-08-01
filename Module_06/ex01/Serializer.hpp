/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:25:36 by berard            #+#    #+#             */
/*   Updated: 2024/08/01 09:59:55 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
	public :
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
	private :
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer	&operator=(Serializer const & rhs);
};

#endif