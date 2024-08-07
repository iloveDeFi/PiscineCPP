/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:32:07 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/07 14:50:21 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b ? a : b);
}

template <typename T>
class Boom {
    public:
        void test(T x, T y) {
            ::swap(x, y);
            std::cout << "Swapped: " << x << " and " << y << std::endl;
            std::cout << "Max is: " << ::max(x, y) << std::endl;
            std::cout << "Min is: " << ::min(x, y) << std::endl;
        }
};

#endif
