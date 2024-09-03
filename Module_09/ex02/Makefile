# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 11:23:46 by bat               #+#    #+#              #
#    Updated: 2024/09/01 12:45:27 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
EXEC = PmergeMe

# Compilateur
CC = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = main.cpp PmergeMe.cpp

# Fichiers objets (générés automatiquement à partir des sources)
OBJS = $(SRCS:.cpp=.o)

# Cible par défaut
all: $(EXEC)

# Génération de l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compilation des fichiers objets
%.o: %.cpp RPN.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet
fclean: clean

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
