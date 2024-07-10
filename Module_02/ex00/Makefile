# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 09:02:44 by bat               #+#    #+#              #
#    Updated: 2024/07/10 09:20:13 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = Canonical
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# List of source files
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp

# Generate list of object files in build directory
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

# Default target
all: $(BUILD_DIR) $(TARGET)

# Linking target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
