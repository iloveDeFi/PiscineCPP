/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:31:09 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 10:34:20 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string _type;

    public:
        // Constructors
        Weapon(const std::string& type);

        // Destructor
        ~Weapon(void);
        
        // My methods : setters and getters
        void    setType(const std::string& newType);
        const std::string&  getType(void) const;
};

#endif