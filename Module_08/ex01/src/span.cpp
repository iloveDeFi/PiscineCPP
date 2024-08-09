/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:12:09 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/09 15:14:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {
    this->_vec.reserve(N);
}

Span::Span(const Span& src) : _N(src._N), _vec(src._vec) {}


Span& Span::operator=(const Span & src) {
    if (this != &src) { 
        this->_N = src._N;
        this->_vec = src._vec;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(unsigned int numberToAdd) {

    if (_vec.size() >= _N)
        throw std::runtime_error("Exeception catched: Sorry container is already full.");
    _vec.push_back(numberToAdd);
    
}

unsigned int Span::shortestSpan(void) const {
    
    if (_vec.size() < 2) {
        throw std::runtime_error("Chiquitos, no span in an empty object. U need at least two values.");
    }

    std::vector<unsigned int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();

    std::vector<unsigned int>::const_iterator it = sortedVec.begin();
    std::vector<unsigned int>::const_iterator next_it = it + 1;

    for (; next_it != sortedVec.end(); ++it, ++next_it) {
        unsigned int currentSpan = *next_it - *it;
        if (currentSpan < shortestSpan) {
            shortestSpan = currentSpan;
        }
    }

    return shortestSpan;
}

unsigned int Span::longestSpan(void) const {
    
    if (_vec.empty() || _vec.size() <= 1)
        throw std::runtime_error("Chiquitos, no span in an empty object. U need at least two values.");

    unsigned int maxElement = *std::max_element(_vec.begin(), _vec.end());
    unsigned int minElement = *std::min_element(_vec.begin(), _vec.end());

    return maxElement - minElement;
}