/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:53:43 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/07 14:56:43 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main() {

    std::cout << "INT EXAMPLE" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Int array before increment: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;
    iter(intArray, intArrayLength, incrementElement);
    std::cout << "Int array after increment: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;

    std::cout << "FLOAT EXAMPLE" << std::endl;
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t floatArrayLength = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "float array before increment: ";
    iter(floatArray, floatArrayLength, printElement);
    std::cout << std::endl;
    iter(floatArray, floatArrayLength, incrementElement);
    std::cout << "float array after increment: ";
    iter(floatArray, floatArrayLength, printElement);
    std::cout << std::endl;

    std::cout << "CHAR EXAMPLE" << std::endl;
    std::string strArray[] = {"Hello", "World", "!"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "String array: ";
    iter(strArray, strArrayLength, printElement);
    std::cout << std::endl;

    return 0;
}
