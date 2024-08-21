/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:40:10 by bat               #+#    #+#             */
/*   Updated: 2024/08/21 23:38:48 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class PmergeMe {
public:
    PmergeMe(int ac, char **av);
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe & src);
    
private:
    std::deque<int> inputDeque;
    std::list<int> inputList;
    std::vector<int> inputVector;
	std::vector<int> inputVectorFJ;

    template <typename T>
    void display(const T& container);
    
    void mergeInsertSortDeque(std::deque<int>& arr);
    void mergeInsertSortList(std::list<int>& arr);
    void mergeInsertSortVector(std::vector<int>& arr);

	void pairing(std::list<int>& inputList, std::list<int>& sortedSubList, std::list<int>& unsortedSubList);
	void recursiveSort(std::list<int>& sortedSubList);
	void binarySearchInsertion(std::list<int>& sortedSubList, std::list<int>& unsortedSubList);
	void fordJohnsonSort(std::vector<int>& vec);
};

#endif
