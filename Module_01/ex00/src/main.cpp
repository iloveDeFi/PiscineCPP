/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:06 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 15:38:38 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombHeap = newZombie("zombHeap");
	zombHeap->announce();
	randomChump("zombStack");
	delete zombHeap;
	return (0);
}