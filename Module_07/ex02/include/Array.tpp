/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:46:05 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/07 16:02:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : elements(nullptr), length(0) {}

// new T[n]() new tab de n elements with () to indicate a value-init is needed
// ex new int[5]() create a tab of 5 integer with the value of 0
template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array& other) : elements(new T[other.length]), length(other.length) {
    for (unsigned int i = 0; i < length; ++i) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements;

        length = other.length;
        elements = new T[length];
        for (unsigned int i = 0; i < length; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw std::out_of_range("Error catched: Index out of boundzzzzzzz");
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length) {
        throw std::out_of_range("Error catched: Index out of boundzzzzzzzz again");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}
