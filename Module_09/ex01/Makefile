# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 23:37:18 by bat               #+#    #+#              #
#    Updated: 2024/09/09 14:14:53 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
EXEC = RPN

# Compilateur
CC = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = main.cpp RPN.cpp

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
