# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:27:45 by bbessard          #+#    #+#              #
#    Updated: 2024/07/04 10:52:54 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
TARGET = megaphone

# Compilateur à utiliser
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++98

# Fichiers source
SRC = megaphone.cpp

# Fichiers objets (générés automatiquement)
OBJ = $(SRC:.cpp=.o)

# Règle par défaut (ce qui est exécuté quand on tape 'make' sans argument)
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour compiler les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés (on peut l'exécuter avec 'make clean')
clean:
	rm -f $(OBJ) $(TARGET)

# Indique que 'clean' n'est pas un fichier
.PHONY: clean
