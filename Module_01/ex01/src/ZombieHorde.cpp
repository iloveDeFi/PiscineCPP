/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:01:04 by bat               #+#    #+#             */
/*   Updated: 2024/07/08 16:52:59 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return nullptr;

    // Call my constructor by default N time
    Zombie* horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
        
    return (horde);
}