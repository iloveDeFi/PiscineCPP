/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:54:18 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 16:55:48 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main() {
    Karen karen;

    std::cout << "DEBUG level:" << std::endl;
    karen.complain("DEBUG");

    std::cout << "\nINFO level:" << std::endl;
    karen.complain("INFO");

    std::cout << "\nWARNING level:" << std::endl;
    karen.complain("WARNING");

    std::cout << "\nERROR level:" << std::endl;
    karen.complain("ERROR");

    return (0);
}