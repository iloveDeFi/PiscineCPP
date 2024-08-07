/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:00:22 by bat               #+#    #+#             */
/*   Updated: 2024/08/07 10:34:37 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return;
}

Serializer::Serializer(Serializer const & src)
{
	(void) src;
	return;
}

Serializer::~Serializer(void)
{
	return;
}

Serializer	&Serializer::operator=(Serializer const & rhs)
{
	(void) rhs;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}