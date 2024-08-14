# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:24:41 by bbessard          #+#    #+#              #
#    Updated: 2024/08/10 15:26:50 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
TARGET = easyfind

# Compilateur C++
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Répertoire des sources
SRC_DIR = src

# Répertoire des fichiers d'en-tête
INCLUDE_DIR = include

# Répertoire des fichiers objets
BUILD_DIR = build

# Liste des fichiers source
SRC = main.cpp

# Liste des fichiers objets correspondants
OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))

# Liste des fichiers d'en-tête nécessaires pour la compilation
DEPS = easyfind.hpp

# Cible par défaut
all: $(BUILD_DIR) $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers source en fichiers objets
$(BUILD_DIR)/%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Création du répertoire de construction s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Nettoyage des fichiers de construction
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Cibles "fantômes" (ne correspondant pas à des fichiers)
.PHONY: all clean
