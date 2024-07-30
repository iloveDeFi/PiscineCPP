# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 10:47:50 by bbessard          #+#    #+#              #
#    Updated: 2024/07/30 10:48:20 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = scalar_converter

# Fichiers sources
SRCS = main.cpp Scalar.cpp

# Fichiers objets (générés à partir des fichiers sources)
OBJS = $(SRCS:.cpp=.o)

# Compilateur et options de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-conversion -std=c++98

# Règle par défaut : création de l'exécutable
all: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Règle pour créer les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Règle pour tout recompiler
re: fclean all

# Ne pas traiter les noms de règles comme des fichiers
.PHONY: all clean fclean re
