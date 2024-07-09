/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:53:10 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 16:43:28 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

// Exercise goal is to use pointers to member functions
class Karen {
    private:
        // Private member functions
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void); 

    public:
        Karen(void);
        ~Karen(void);
        void complain(std::string level);
};

#endif