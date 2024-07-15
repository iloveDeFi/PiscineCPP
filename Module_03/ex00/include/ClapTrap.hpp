/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:14:32 by bat               #+#    #+#             */
/*   Updated: 2024/07/15 13:25:50 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int _health;
        int _energy;
        int _damage;

    public:
        // Canonical form
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap(void);
        ClapTrap& operator=(const ClapTrap &other);
        // Public member functions
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void displayInfos(void) const;
};

#endif