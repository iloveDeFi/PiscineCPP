/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:55:24 by bat               #+#    #+#             */
/*   Updated: 2024/09/01 12:46:52 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {

    srand(static_cast<unsigned int>(time(NULL)));
    
    for (int i = 1; i < ac; ++i) {
        int value = std::atoi(av[i]);
        if (value <= 0) {
            std::cerr << "Error: Invalid input value \"" << av[i]
                << "\". Only positive integers are allowed." << std::endl;
            exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
        inputVector.push_back(value);
        inputVectorFJ.push_back(value);
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
    
    clock_t start4 = clock();
    fordJohnsonSort(inputVectorFJ);
    clock_t end4 = clock();
    double time4 = static_cast<double>(end4 - start4) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    display(inputDeque);
    std::cout << std::endl;
    std::cout << "First using the simple version of MergeInsort" << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque container: " 
              << time1 << " µs (microsecondes)" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " 
              << time2 << " µs (microsecondes)" << std::endl;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector container: " 
              << time3 << " µs (microsecondes)" << std::endl;
              
    std::cout << std::endl;
    std::cout << "Then trying to properly rerpresent the Ford Johnson algorithm." << std::endl;
    std::cout << "Time to process a range of " << inputVectorFJ.size() << " elements with std::vector container: "
        << time4 << " µs (microsecondes)" << std::endl;
    std::cout << std::endl;

    bool areSizesEqual = (inputDeque.size() == inputVector.size()) &&
                         (inputVector.size() == inputList.size());
    if (areSizesEqual) {
        std::cout << "Nice, the sorted sequences have an equal size Notorious." << std::endl;
    } else {
        std::cout << "Oopsi Jack, the sorted sequences are not equal." << std::endl;
    }

    if (areSizesEqual) {
        bool equal = true;

        std::vector<int>::iterator vecIt = inputVector.begin();
        for (std::deque<int>::iterator deqIt = inputDeque.begin(); deqIt != inputDeque.end(); ++deqIt, ++vecIt) {
            if (*deqIt != *vecIt) {
                equal = false;
                break;
            }
        }

        if (equal) {
            std::list<int>::iterator listIt = inputList.begin();
            vecIt = inputVector.begin();
            for (; listIt != inputList.end(); ++listIt, ++vecIt) {
                if (*listIt != *vecIt) {
                    equal = false;
                    break;
                }
            }
        }

        if (equal) {
            std::cout << "Sheesh, the sorted sequences are properly equal Big." << std::endl;
        } else {
            std::cout << "Oopsi Jack, the sorted sequences are not equal." << std::endl;
        }
    } else {
        std::cout << "Mmmm nope, container sizes are not equal Averell." << std::endl;
    }
}


PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : inputDeque(src.inputDeque), inputList(src.inputList), inputVector(src.inputVector) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
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

// Fonction de pairage (Pairing)
void PmergeMe::pairing(std::list<int>& inputList, std::list<int>& sortedSubList, std::list<int>& unsortedSubList) {
    std::list<int>::iterator it = inputList.begin();
    while (it != inputList.end()) {
        int first = *it;
        ++it;
        if (it != inputList.end()) {
            int second = *it;
            ++it;
            if (first > second) {
                sortedSubList.push_back(first);
                unsortedSubList.push_back(second);
            } else {
                sortedSubList.push_back(second);
                unsortedSubList.push_back(first);
            }
        } else {
            sortedSubList.push_back(first);
        }
    }
}

// Tri récursif (Recursive Sort)
void PmergeMe::recursiveSort(std::list<int>& sortedSubList) {
    if (sortedSubList.size() <= 1) {
        return;
    }

    std::list<int>::iterator middle = sortedSubList.begin();
    std::advance(middle, sortedSubList.size() / 2);

    std::list<int> left(sortedSubList.begin(), middle);
    std::list<int> right(middle, sortedSubList.end());

    recursiveSort(left);
    recursiveSort(right);

    sortedSubList.clear();
    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft < *itRight) {
            sortedSubList.push_back(*itLeft);
            ++itLeft;
        } else {
            sortedSubList.push_back(*itRight);
            ++itRight;
        }
    }

    while (itLeft != left.end()) {
        sortedSubList.push_back(*itLeft);
        ++itLeft;
    }
    while (itRight != right.end()) {
        sortedSubList.push_back(*itRight);
        ++itRight;
    }
}

// Insertion par recherche binaire (Binary Search Insertion)
void PmergeMe::binarySearchInsertion(std::list<int>& sortedSubList, std::list<int>& unsortedSubList) {
    for (std::list<int>::iterator it = unsortedSubList.begin(); it != unsortedSubList.end(); ++it) {
        int element = *it;

        std::list<int>::iterator low = sortedSubList.begin();
        std::list<int>::iterator high = sortedSubList.end();

        while (low != high) {
            std::list<int>::iterator mid = low;
            std::advance(mid, std::distance(low, high) / 2);

            if (*mid < element) {
                low = ++mid;
            } else {
                high = mid;
            }
        }

        sortedSubList.insert(low, element);
    }
}

// Fonction principale Ford-Johnson Sort
void PmergeMe::fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::list<int> inputList(vec.begin(), vec.end());
    std::list<int> sortedSubList;
    std::list<int> unsortedSubList;

    pairing(inputList, sortedSubList, unsortedSubList);
    recursiveSort(sortedSubList);
    binarySearchInsertion(sortedSubList, unsortedSubList);

    // Reconversion de la liste en vecteur
    vec.assign(sortedSubList.begin(), sortedSubList.end());
}