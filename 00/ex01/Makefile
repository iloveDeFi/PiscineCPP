# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:45:23 by bbessard          #+#    #+#              #
#    Updated: 2024/07/03 11:10:51 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = PhoneBook

# Compilateur et options de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Répertoires
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Fichiers source et objets
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Règle par default
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I $(INCDIR) -o $@ -c $<

# Création du répertoire des objets
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Nettoyage des fichiers compilés
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

# Gestion des dépendances
.PHONY: all clean fclean re
