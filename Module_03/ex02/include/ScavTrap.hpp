/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:41:59 by bat               #+#    #+#             */
/*   Updated: 2024/07/15 14:15:25 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {
    public:
        // Canonical form
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap(void);
        ScavTrap &operator=(const ScavTrap &other);

        void attack(std::string const &target);
        void guardGate();
};

# endif