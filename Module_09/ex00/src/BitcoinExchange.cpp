/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:42:00 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/16 18:57:08 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

btc::btc(const std::string& filename) : _filename(filename) {
    loadExchangeRates();
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

void btc::loadExchangeRates() {
    
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << _filename << std::endl;
        throw std::runtime_error("File cannot be opened: " + _filename);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;
        float rate;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            date = trim(date);
            rateStr = trim(rateStr);

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            try {
                rate = std::stof(rateStr);
                if (rate < 0) {
                    std::cerr << "Error: invalid rate => " << line << std::endl;
                    continue;
                }
                _exchangeRates[date] = rate;
            } catch (...) {
                std::cerr << "Error: bad input => " << date << std::endl;
            }
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

void btc::printData() const {
    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string quantityStr;
        float quantity;

        if (std::getline(ss, date, '|') && std::getline(ss, quantityStr)) {
            date = trim(date);
            quantityStr = trim(quantityStr);

            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

             if (dateChecker(date) == -1) {
                std::cerr << "Error: date not found in database => " << date << std::endl;
                continue;
            }

            try {
                quantity = std::stof(quantityStr);
                if (quantity < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
                else if (quantity > 1000) {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
            } catch (...) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            float rate = getExchangeRate(date);
            if (rate == -1) {
                std::cerr << "Error: rate not found for date " << date << std::endl;
                continue;
            }

            std::cout << date << " => " << quantity << " = " << quantity * rate << std::endl;
        } else {
            std::cerr << "Error: bad input => " << date << std::endl;
        }
    }
}

int btc::dateChecker(const std::string& date) const {
    if (_exchangeRates.find(date) != _exchangeRates.end()) {
        return 0;
    } else {
        return -1;
    }
}


// Functionitos to test my mapitos
// void btc::printMap(const std::map<std::string, float>& _exchangeRates) const {
//     std::map<std::string, float>::const_iterator it;
//     int x = 0;

//     for (it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
//         std::cout << "Date: " << it->first << " - Exchange Rate: " << it->second << std::endl;        
//     }
// }
