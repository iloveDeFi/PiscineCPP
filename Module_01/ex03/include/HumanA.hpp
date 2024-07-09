/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:31:14 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 10:39:46 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

// HumanA will ALWAYS be armed
// While HumanA takes the Weapon in its constructor, HumanB doesn’t
class HumanA {
    private:
        std::string _name;
        Weapon& _weapon;

    public:
        // Constructor with param
        HumanA(const std::string name, Weapon& weapon);
        
        // Destructor
        ~HumanA(void);

        // Methods setters and getters
       void attack(void) const;
};

#endif
