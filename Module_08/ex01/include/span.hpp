/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:09:56 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/09 14:13:58 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {

    private: 
        unsigned int _N;
        std::vector<unsigned int> _vec;
        
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span & src);
        Span& operator=(const Span & src);

        void addNumber(unsigned int numberToAdd);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;
};

#endif