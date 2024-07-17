/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:41:59 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 13:10:54 by bbessard         ###   ########.fr       */
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
		ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap(void);
        ScavTrap &operator=(const ScavTrap &other);

        virtual void attack(std::string const &target);
        void guardGate();
};

# endif