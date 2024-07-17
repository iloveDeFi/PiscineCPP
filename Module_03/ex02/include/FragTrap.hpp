/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:14:28 by bat               #+#    #+#             */
/*   Updated: 2024/07/17 11:35:24 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        // Canonical form
		FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap(void);
        FragTrap &operator=(const FragTrap &other);

        void attack(std::string const &target);
        void highFivesGuys(void);
};

#endif