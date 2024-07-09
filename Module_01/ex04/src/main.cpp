/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:53:38 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 14:46:38 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Argc error: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

      
    if (s1.empty() || s2.empty()) { 
        std::cerr << "Error: Strings to replace and replacement cannot be empty." << std::endl;
        return 1;
    }

    Replace replacer(filename, s1, s2);
    replacer.launchReplacement();

    return (0);
}
