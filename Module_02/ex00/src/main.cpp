/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:02:51 by bat               #+#    #+#             */
/*   Updated: 2024/07/10 13:21:42 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
    // Fixed class objects a, b, c
    // Default constructor
    Fixed a;
    
    // Copie constructor a to b
    Fixed b(a);

    // Default constructor
    Fixed c;

    // Copy assignement operator
    c = b;

    // Method calls on my objects
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return (0);
}