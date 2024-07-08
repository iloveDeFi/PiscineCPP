/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:12:13 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/08 11:51:40 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// On stack, destroying itself when function ends
void randomChump(std::string name) {
    Zombie zombStack = Zombie(name);
    zombStack.announce(name);
}
