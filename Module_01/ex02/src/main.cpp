/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:58:34 by bat               #+#    #+#             */
/*   Updated: 2024/07/08 17:27:00 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    std::string brainSTR = "HI THIS IS BRAIN";
    std::string* stringPTR = &brainSTR;
    std::string& stringREF = brainSTR;

    // display the address in memory of the string
    std::cout << "Address in memory of the string: " << &brainSTR << std::endl;
    std::cout << "Address in memory by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in memory by stringREF: " << &stringREF << std::endl;
    // display the string using pointer
    std::cout << "Display string using pointer: " << *stringPTR << std::endl;
    // display string using reference
    std::cout << "Display string using reference: " << stringREF << std::endl;

    return (0);
};