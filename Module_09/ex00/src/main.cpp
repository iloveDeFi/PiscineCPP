#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int ac, char **av) {

     if (ac == 1) {
        std::cout << "Error: could not open file" << std::endl;
    } else if (ac > 2) {
        std::cout << "Error: to many arguments. Should be 2" << std::endl;
    }

    // Ouvrir le fichier CSV
    std::ifstream file("fichier.csv");
    
    // Vérifier si le fichier est bien ouvert
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    std::string line;
    // Lire le fichier ligne par ligne
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

    // Fermer le fichier
    file.close();
    return 0;
}
