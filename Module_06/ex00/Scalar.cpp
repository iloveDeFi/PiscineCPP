/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:20:43 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/07 10:33:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <cmath>

ScalarConverter::ScalarConverter(void) {
    
}

ScalarConverter::~ScalarConverter(void) {
    
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return(*this);
}

void ScalarConverter::convert(const std::string& literal) {
    // Check for char literal
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Handle special float values
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }

    // Handle special double values
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    char* endPtr;

    long intVal = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0' && intVal >= std::numeric_limits<int>::min() && intVal <= std::numeric_limits<int>::max()) {
        std::cout << "char: ";
        if (std::isprint(static_cast<char>(intVal))) {
            std::cout << "'" << static_cast<char>(intVal) << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << intVal << std::endl;
        std::cout << "float: " << static_cast<float>(intVal) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(intVal) << ".0" << std::endl;
        return;
    }

    float floatVal = std::strtof(literal.c_str(), &endPtr);
    if (*endPtr == 'f' && *(endPtr + 1) == '\0') {
        std::cout << "char: ";
        if (floatVal >= std::numeric_limits<char>::min() && floatVal <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(floatVal))) {
            std::cout << "'" << static_cast<char>(floatVal) << "'" << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
        std::cout << "int: ";
        if (floatVal >= std::numeric_limits<int>::min() && floatVal <= std::numeric_limits<int>::max()) {
            std::cout << static_cast<int>(floatVal) << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
        std::cout << "float: " << floatVal << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatVal) << ".0" << std::endl;
        return;
    }

    double doubleVal = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: ";
        if (doubleVal >= std::numeric_limits<int>::min() && doubleVal <= std::numeric_limits<int>::max()) {
            std::cout << static_cast<int>(doubleVal) << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
        std::cout << "float: ";
        if (doubleVal >= -std::numeric_limits<float>::max() && doubleVal <= std::numeric_limits<float>::max()) {
            std::cout << static_cast<float>(doubleVal) << "f" << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
        std::cout << "double: " << doubleVal << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
