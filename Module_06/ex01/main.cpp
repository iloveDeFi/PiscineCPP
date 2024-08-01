/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:59:16 by bat               #+#    #+#             */
/*   Updated: 2024/08/01 09:59:19 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

void	initData(Data *cat)
{
	cat->race = "cat";
	cat->name = "Dusty";
	cat->age = 4;
}

void	printData(Data *cat)
{
	std::cout << "Race : " << cat->race << std::endl;
	std::cout << "Name : " << cat->name << std::endl;
	std::cout << "Age : " << cat->age << std::endl;
	std::cout << "Pointer : " << cat << std::endl;
}

int	main(void)
{
	Data		animal;

	initData(&animal);

	std::cout << "~ Here are the original values ~" << std::endl;
	printData(&animal);
	std::cout << std::endl;

	std::cout << "~ Let's do some casting now ~" << std::endl;
	uintptr_t 	raw = Serializer::serialize(&animal);
	Data		*new_animal = Serializer::deserialize(raw);
	std::cout << std::endl;

	std::cout << "~And now, Let's check that the values are always the same" << std::endl;
	printData(new_animal);
	std::cout << std::endl;
	return (0);
}