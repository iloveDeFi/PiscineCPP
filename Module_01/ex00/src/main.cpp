/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:06 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 11:49:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates zombie, name it, and return it 
so you can use it outside of the function scope. */
Zombie	*newZombie(std::string name);

/* It creates a zombie, name it, and the zombie announces itself. */
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*zombHeap = newZombie("zombHeap");
	zombHeap->announce();
	randomChump("zombStack");
	delete zombHeap;
	return (0);
}