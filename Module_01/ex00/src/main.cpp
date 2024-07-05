/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:06 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/05 14:36:37 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie	Pepito = Zombie("uno");
	Zombie*	Chorizo = new Zombie("dos");
	Zombie* zombinis = new Zombie[42];

	// Do some stuff here

	delete Chorizo; // Chorizo is destroyed

	delete [] zombinis; // zombinis are destroyed
	
	return (0); // Pepito is destroyed
}