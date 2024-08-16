/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:06:17 by bat               #+#    #+#             */
/*   Updated: 2024/08/16 23:48:50 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RPN.cpp
#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & src) : _stackitos(src._stackitos) {}

RPN& RPN::operator=(const RPN & src) {
    if (this != &src) {
        this->_stackitos = src._stackitos;
    }
    return *this;
}

int RPN::evaluateRPN(const std::string& expression) const {
    std::istringstream iss(expression);
    std::stack<int> stackitos;  // Utilisation d'une pile locale

    std::string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            stackitos.push(std::stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stackitos.size() < 2) {
                throw std::runtime_error("Invalid expression: Not enough operands");
            }

            int b = stackitos.top(); stackitos.pop();
            int a = stackitos.top(); stackitos.pop();

            if (token == "+") stackitos.push(a + b);
            else if (token == "-") stackitos.push(a - b);
            else if (token == "*") stackitos.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Division by zero");
                stackitos.push(a / b);
            }
        } else {
            throw std::runtime_error("the invalid token: " + token);
        }
    }

    if (stackitos.size() != 1) {
        throw std::runtime_error("Invalid expression: Remaining operands after evaluation");
    }

    return stackitos.top();
}

