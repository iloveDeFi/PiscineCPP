/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:54:20 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/15 09:31:01 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    btc exchange(argv[1]);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        float value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date = btc::trim(date);
            valueStr = btc::trim(valueStr);

            try {
                value = static_cast<float>(std::atof(valueStr.c_str()));
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
            } catch (...) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            float rate = exchange.getValue(date);
            if (rate == -1) {
                std::cerr << "Error: date not found." << std::endl;
            } else {
                std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << value * rate << std::endl;
            }
        }
    }

    return 0;
}
