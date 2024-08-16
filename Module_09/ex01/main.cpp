/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:09:59 by bat               #+#    #+#             */
/*   Updated: 2024/08/16 23:46:38 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    RPN notation;
    try {
        int result = notation.evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Tests from subject
    // ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
    // 42

    // ./RPN "7 7 * 7 -"
    // 42

    // ./RPN "1 2 * 2 / 2 * 2 4 - +"
    // 0

    // ./RPN "(1 + 1)"
    // Error

    return 0;
}
