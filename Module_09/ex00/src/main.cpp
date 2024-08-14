#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>


int main(int ac, char **av) {
    if (ac != 3) {
        if (ac < 3) {
            std::cout << "Error: not enough arguments. Should be 3" << std::endl;
        } else {
            std::cout << "Error: too many arguments. Should be 3" << std::endl;
        }
        return 1; 
    }

    if (std::strcmp(av[1], "btc") != 0) {
        std::cout << "Error: program name must be: btc" << std::endl;
        return 1;
    }

    std::ifstream file(av[2]);
    if (!file.is_open()) {
        std::cout << "Error: argument 2 must be an openable file " << av[2] << std::endl;
        return 1;
    }

    std::cout << "File " << av[2] << " opened successfully!" << std::endl;


    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> row;

        // Séparer les valeurs avec la virgule comme délimiteur
        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }

        // Traiter les valeurs de la ligne
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << "Colonne " << i + 1 << ": " << row[i] << std::endl;
        }
        std::cout << "---- Fin de la ligne ----" << std::endl;
    }

    file.close();
    return 0;
}
