/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:31:18 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 10:39:40 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

// HumanB may not always have a Weapon
// While HumanA takes the Weapon in its constructor, HumanB doesn’t
class HumanB {
    private:
        std::string _name;
        Weapon* _weapon;

    public:
        // Constructor
        HumanB(const std::string& name);

        // Destructor
        ~HumanB(void);
        
        // Methods setters and getters
        void attack(void) const;
        void setWeapon(Weapon& weapon);
};

#endif