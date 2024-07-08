/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:10 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 11:47:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// On the heap to survive outside the scope
// to use it outside the function
Zombie* newZombie(std::string name) {
    return (new Zombie(name));
}
