/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:31:12 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/30 17:51:10 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
    int a = 2;
    int b = 3;

    std::cout << "------- MAIN TEST ------" << std::endl;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "------- MY TESTS ------" << std::endl;
    
    Boom<int> intBoom;
    intBoom.test(5, 7);

    Boom<float> floatBoom;
    floatBoom.test(6.6, 3.4);

    Boom<char> charBoom;
    charBoom.test('a', 'z');
    
    Boom<std::string> stringBoom;
    stringBoom.test("chaine1", "chaine2");

    return 0;
}
