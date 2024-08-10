/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:38:58 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/10 15:20:45 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {
    // protected:
    //     Container c; // to underlying container
    public:
        MutantStack();
        MutantStack(const MutantStack& src);
        virtual ~MutantStack();
        MutantStack& operator=(const MutantStack& src);

        // Check cplusplus.com if needed, stack depends from its underlying container deque
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
