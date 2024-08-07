/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:05:47 by bat               #+#    #+#             */
/*   Updated: 2024/08/07 15:52:44 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // 1)
        std::cout << "-----------------Testing default constructor" << std::endl;
        Array<int> arr1;
        std::cout << "Default constructor, size: " << arr1.size() << std::endl;
        
        // 2)
        std::cout << "-------------------Testing constructor with size" << std::endl;
        Array<int> arr2(5);
        std::cout << "Constructor with size 5, size: " << arr2.size() << std::endl;

        // 3)
        std::cout << "--------------------Testing element access + default initz to 0" << std::endl;
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        // 4)
        std::cout << "---------------------Testing copy constructorr (should be size 5)" << std::endl;
        Array<int> arr3 = arr2;
        std::cout << "Copy constructor, size: " << arr3.size() << std::endl;

        // 5)
        std::cout << "---------------------Modifying arr3 should not affect arr2" << std::endl;
        arr3[0] = 42;
        std::cout << "arr3[0] = " << arr3[0] << std::endl;
        std::cout << "arr2[0] = " << arr2[0] << std::endl;

        // 6)
        std::cout << "---------------------Testing assignment operator(should be size 5)" << std::endl;
        Array<int> arr4;
        arr4 = arr3;
        std::cout << "Assignment operator, size: " << arr4.size() << std::endl;

        // 7)
        std::cout << "---------------------Testing out of bounds access - Try catch test" << std::endl;
        std::cout << "Accessing out of bounds element" << std::endl;
        std::cout << arr4[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
