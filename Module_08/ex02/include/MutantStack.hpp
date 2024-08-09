/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:38:58 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/09 15:42:59 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MutantStack {
    private:
        T _num;
        std::stack<T> _stackitos;

    public:
        std::stack<T>::iterator it;
        std::stack<Tt>::iterator ite;

        MutantStack(void);
        MutantStack(T num);
        ~MutantStack(void);
        MutantStack(const MutantStack & src);
        MutantStack& operator=(const MutantStack & src);

        void emplace(T value);
        bool empty(void) const;
        void pop(void);
        void push(T value);
        size_t size(void) const;
        void swap(MutantStack & other);
        T top(void) const;
};

#include "MutantStack.tpp"

#endif
