/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:54:20 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/15 10:56:44 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    try {
        btc exchange(argv[1]);

        std::string line;
        while (std::getline(std::cin, line)) {
            std::stringstream ss(line);
            std::string date;
            float value;

            if (std::getline(ss, date, '|') && ss >> value) {
                date = btc::trim(date);

                if (!btc::isValidDate(date)) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }

                float rate = exchange.getExchangeRate(date);
                if (rate == -1) {
                    std::cerr << "Error: date not found => " << date << std::endl;
                    continue;
                }

                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
