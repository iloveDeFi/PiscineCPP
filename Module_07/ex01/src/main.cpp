/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:53:43 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/30 18:03:22 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Int array before increment: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementElement);

    std::cout << "Int array after increment: ";
    iter(intArray, intArrayLength, printElement);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "!"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArrayLength, printElement);
    std::cout << std::endl;

    return 0;
}
