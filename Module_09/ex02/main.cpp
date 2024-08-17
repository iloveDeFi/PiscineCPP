/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:25:38 by bat               #+#    #+#             */
/*   Updated: 2024/08/17 13:53:13 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if(ac < 2) {
        std::cerr << "Usage: " << av[0] << " [list of integers]" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < ac; ++i) {
        int num = std::atoi(av[i]);
        numbers.push_back(num);
    }

    std::cout << "Numbers from argv are: ";
    for(std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return (0);
}