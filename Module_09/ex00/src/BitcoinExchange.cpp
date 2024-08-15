/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:42:00 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/15 11:03:14 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

btc::btc(const std::string& filename) : _filename(filename) {
    loadExchangeRates(filename);
}

btc::~btc() {

}

btc::btc(const btc & src) : _filename(src._filename), _exchangeRates(src._exchangeRates) {

}

btc& btc::operator=(const btc & src) {
    if (this != &src) {
        this->_filename = src._filename;
        this->_exchangeRates = src._exchangeRates;
    }
    return (*this);
}

void btc::loadExchangeRates(const std::string& dataFile) {
    std::ifstream file(dataFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        throw std::runtime_error("File cannot be opened.");
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        float value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date = trim(date);
            valueStr = trim(valueStr);

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            try {
                value = static_cast<float>(std::atof(valueStr.c_str()));
                if (value < 0 || value > 1000) {
                    std::cerr << "Error: " << (value < 0 ? "not a positive number." : "too large a number.") << std::endl;
                    continue;
                }
            } catch (...) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            _exchangeRates[date] = value;
        }
    }
    file.close();
}

float btc::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.end() || (it->first != date && it == _exchangeRates.begin())) {
        return -1;
    }
    if (it->first != date && it != _exchangeRates.begin()) {
        --it;
    }
    return it->second;
}

std::string btc::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool btc::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    return true;
}