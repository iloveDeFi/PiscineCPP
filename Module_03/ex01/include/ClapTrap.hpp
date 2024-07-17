/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:41:40 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 11:18:42 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int _health;
        int _energy;
        int _damage;

    public:
        // Canonical form
		ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap(void);

        // Public member functions
        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void displayInfos(void) const;
};

#endif