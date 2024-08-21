/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:55:24 by bat               #+#    #+#             */
/*   Updated: 2024/08/21 14:46:03 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe(int ac, char **av) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 1; i < ac; ++i) {
        int value = std::atoi(av[i]);
        if (value <= 0) {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
            exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
        inputVector.push_back(value);
    }
    
    std::cout << "Before: ";
    display(inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;

    clock_t start3 = clock();
    mergeInsertSortVector(inputVector);
    clock_t end3 = clock();
    double time3 = static_cast<double>(end3 - start3) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    display(inputDeque);
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " << time1 << " µs (microsecondes)" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " µs (microsecondes)" << std::endl;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector container: " << time3 << " µs (microsecondes)" << std::endl;

    // Verify if the sorted sequences are equal
    bool equal = (inputDeque.size() == inputVector.size());
    if (equal) {
        std::vector<int>::iterator vecIt = inputVector.begin();
        for (std::deque<int>::iterator deqIt = inputDeque.begin(); deqIt != inputDeque.end(); ++deqIt, ++vecIt) {
            if (*deqIt != *vecIt) {
                equal = false;
                break;
            }
        }
    }

    if (equal) {
        std::cout << "The sorted sequences are equal." << std::endl;
    } else {
        std::cout << "The sorted sequences are not equal." << std::endl;
    }
}

PmergeMe::~PmergeMe() {
    // Destructor: Nothing special to do, as STL containers handle their own memory.
}

PmergeMe::PmergeMe(const PmergeMe &src) : inputDeque(src.inputDeque), inputList(src.inputList), inputVector(src.inputVector) {
    // Copy constructor: Initialize from another PmergeMe object
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        // Assignment operator: Protect against self-assignment
        inputDeque = src.inputDeque;
        inputList = src.inputList;
        inputVector = src.inputVector;
    }
    return *this;
}

template <typename T>
void PmergeMe::display(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1) {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp) {
            *it2 = *(std::prev(it2));
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1) {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp) {
            *it2 = *(std::prev(it2));
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        int temp = arr[i];
        std::size_t j = i;
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
}
