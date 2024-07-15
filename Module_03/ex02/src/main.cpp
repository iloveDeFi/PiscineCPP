/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:15:34 by bat               #+#    #+#             */
/*   Updated: 2024/07/15 20:30:07 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--------------BUILDING PHASE--------------" << std::endl;
    FragTrap robot1("Mad");
    FragTrap robot2("Max");

    robot1.displayInfos();
    robot2.displayInfos();

    std::cout << "--------------ATTACKING PHASE--------------" << std::endl;
    robot1.attack("Max");
    robot2.takeDamage(30);
    robot2.displayInfos();
    
    std::cout << "--------------REPAIRING PHASE--------------" << std::endl;
    robot2.beRepaired(30);
    robot2.displayInfos();
    robot2.highFivesGuys();
    
    return (0);
}