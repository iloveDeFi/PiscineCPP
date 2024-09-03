/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:25:38 by bat               #+#    #+#             */
/*   Updated: 2024/09/01 12:42:19 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
    {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }
	PmergeMe pmergeMe(ac, av);
	// (void)pmergeMe;
    return 0;
}