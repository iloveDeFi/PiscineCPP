/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:13 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 14:52:19 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// On stack, destroying itself when function ends
void randomChump(std::string name) {
    Zombie zombStack = Zombie(name);
    zombStack.announce();
}
