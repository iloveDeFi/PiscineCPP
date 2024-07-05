/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:30:15 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/01 14:34:56 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av) 
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for (int i = 1; i < ac; i++) 
        {
            for (int j = 0; av[i][j] != '\0'; ++j) 
                std::cout << (char)std::toupper(av[i][j]);
        }
        std::cout << std::endl;
    }
    return 0;
}
