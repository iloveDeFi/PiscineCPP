/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:58:52 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/16 23:41:40 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RPN.hpp
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
        std::stack<int> _stackitos;

    public:
        RPN();
        ~RPN();
        RPN(const RPN & src);
        RPN& operator=(const RPN & src);

        int evaluateRPN(const std::string& expression) const;
};

#endif
