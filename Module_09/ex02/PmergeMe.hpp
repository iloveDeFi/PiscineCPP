/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:40:10 by bat               #+#    #+#             */
/*   Updated: 2024/08/17 13:53:51 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>

class PmergeMe {
    private:
        std::vector<unsigned int> _vec;
        std::deque<unsigned int> _deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe & src);
        PmergeMe& operator=(const PmergeMe & src);
};

#endif