/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:42:00 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/14 18:03:17 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

btc::btc(const std::string& filename) {
    csvLoadData();
}

btc::~btc() {

}

btc::btc(const btc & src) : _btcData(src._btcData) {

}

btc& btc::operator=(const btc & src) {
    if (this != &src) {
        this->_btcData = src._btcData;
    }
    return (*this);
}

float btc::getValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _btcData.lower_bound(date);
    if (it == _btcData.end() || (it->first != date && it == _btcData.begin())) {
        return -1; // Date non trouvée
    }
    if (it->first != date && it != _btcData.begin()) {
        --it;
    }
    return it->second;
}

std::string btc::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// (format YYYY-MM-DD)
bool btc::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    return true;
}

// Fonction pour charger les données depuis le fichier CSV
void btc::csvLoadData() {
    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    // Lire et ignorer l'en-tête
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        float value;

        // Lire la date et la valeur séparées par '|'
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            // Enlever les espaces superflus
            date = trim(date);
            valueStr = trim(valueStr);

            // Vérifier la validité de la date
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            // Convertir la valeur en float et vérifier les erreurs
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

            // Ajouter à la map
            _btcData[date] = value;
        }
    }
    file.close();
}