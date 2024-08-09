/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:13:44 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/09 15:38:00 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(T num) : _num(num) {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & src) : _num(src._num), _stackitos(src._stackitos) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack & src) {
    if (this != &src) {
        _num = src._num;
        _stackitos = src._stackitos;
    }
    return *this;
}

template <typename T>
void MutantStack<T>::emplace(T value) {
    _stackitos.push(value);
}

template <typename T>
bool MutantStack<T>::empty(void) const {
    return _stackitos.empty();
}

template <typename T>
void MutantStack<T>::pop(void) {
    if (!_stackitos.empty()) {
        _stackitos.pop();
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

template <typename T>
void MutantStack<T>::push(T value) {
    _stackitos.push(value);
}

template <typename T>
size_t MutantStack<T>::size(void) const {
    return _stackitos.size();
}

template <typename T>
void MutantStack<T>::swap(MutantStack & other) {
    _stackitos.swap(other._stackitos);
    std::swap(_num, other._num);
}

template <typename T>
T MutantStack<T>::top(void) const {
    if (!_stackitos.empty()) {
        return _stackitos.top();
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

#endif
