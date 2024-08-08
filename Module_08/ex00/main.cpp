/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:21:30 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/08 17:15:11 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "------------ VECTOR TEST ----------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    int arr1[] = { 1, 3, 2, 5, 4 };
    std::vector<int> vec(arr1, arr1 + 5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 30 at index: " << std::distance(vec.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "Found value 100 at index: " << std::distance(vec.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "------------ LIST TEST ------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    int arr2[] = { 1, 3, 2, 5, 4 };
    std::list<int> list(arr2, arr2 + 5);
    
    try {
        std::list<int>::iterator it = easyfind(list, 3);
        std::cout << "Found value 30 at index: " << std::distance(list.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(list, 100);
        std::cout << "Found value 100 at index: " << std::distance(list.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "------------ DEQUE TEST -----------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    int arr3[] = { 1, 3, 2, 5, 4 };
    std::deque<int> deque(arr3, arr3 + 5);
    
    try {
        std::deque<int>::iterator it = easyfind(deque, 3);
        std::cout << "Found value 30 at index: " << std::distance(deque.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deque, 100);
        std::cout << "Found value 100 at index: " << std::distance(deque.begin(), it)
            << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


