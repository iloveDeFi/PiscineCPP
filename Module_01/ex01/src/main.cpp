/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:00:34 by bat               #+#    #+#             */
/*   Updated: 2024/07/08 16:46:22 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// 1) delete ALL the Zombies when you don’t need them anymore.
// 2) Call announce() on each one of the Zombies to test the function
// 3) Allocates N Zombie and init each one with the name given in parameter
int main(void) {
    int hordeSize; 

    hordeSize = 6;
    
    Zombie *horde = zombieHorde(hordeSize, "Bison");

    for (int i = 0; i < hordeSize; i++)
        horde[i].announce();

    delete [] horde;
    
    return (0);
}
