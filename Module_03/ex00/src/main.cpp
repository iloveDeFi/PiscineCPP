/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:34 by bat               #+#    #+#             */
/*   Updated: 2024/07/15 13:32:38 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "--------------BUILDING PHASE--------------" << std::endl;
    ClapTrap person1("Arthur");
    ClapTrap person2("Perceval");

    person1.displayInfos();
    person2.displayInfos();

    std::cout << "--------------ATTACKING PHASE--------------" << std::endl;
    person1.attack("Perceval");
    person2.takeDamage(2);
    person2.displayInfos();
    
    std::cout << "--------------REPAIRING PHASE--------------" << std::endl;
    person2.beRepaired(2);
    person2.displayInfos();

    return (0);
}