/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:34 by bat               #+#    #+#             */
/*   Updated: 2024/07/15 20:06:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--------------BUILDING PHASE--------------" << std::endl;
    ScavTrap robot1("Tom");
    ScavTrap robot2("Jerry");

    robot1.displayInfos();
    robot2.displayInfos();

    std::cout << "--------------ATTACKING PHASE--------------" << std::endl;
    robot1.attack("Jerry");
    robot2.takeDamage(20);
    robot2.displayInfos();
    
    std::cout << "--------------REPAIRING PHASE--------------" << std::endl;
    robot2.guardGate();
    robot2.beRepaired(20);
    robot2.displayInfos();

    return (0);
}