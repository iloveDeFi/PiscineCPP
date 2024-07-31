#!/bin/bash

#region test and make folders ----------------------------------------------------------------------------
if [ $# -ne 2 ]; then
    echo "Usage: $0 <path> <name>"
    exit 1
fi

cd $1
latest_folder=$(find . -type d -name "ex*" | sort -r | head -n 1 | sed 's/..ex//')

if [ -z "$latest_folder" ]; then
    latest_folder=-1
fi

latest_folder=$((latest_folder+1))
latest_folder=$(printf "%02d" $latest_folder)
mkdir ex$latest_folder

cd ex$latest_folder

mkdir bin
echo "*.bin
!spec/*.bin" > ./bin/.gitignore

mkdir inc
echo "!.gitignore" > ./inc/.gitignore

mkdir obj
echo "*.o 
!spec/*.o" > ./obj/.gitignore

mkdir src
echo "!.gitignore" > ./src/.gitignore

touch Makefile
touch ./src/main.cpp
touch ./src/$2.cpp
touch ./inc/$2.h
touch ./inc/$2.hpp

#endregion

#region Makefile -----------------------------------------------------------------------------------------

echo \
'BINARY := ex'$latest_folder'.bin
CXX := g++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRC_DIR := ./src/
INC_DIR := ./inc/
OBJ_DIR := ./obj/
BIN_DIR := ./bin/
SOURCES := $(wildcard $(SRC_DIR)*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)$(BINARY)

all: $(EXECUTABLE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)* $(BIN_DIR)*

re: clean all

.PHONY: all clean re' > Makefile

#endregion

#region class.hpp ----------------------------------------------------------------------------------------

echo \
'#ifndef '$2'_H
#define '$2'_H

#include <iostream>

class '$2' {
    private:
        int value; // Private attribute

    public:
        '$2'(); // Default constructor
        '$2'(const '$2'&); // Copy constructor
        '$2'& operator=(const '$2'&); // Copy assignment
        ~'$2'(); // Destructor
};

#endif' > ./inc/$2.hpp

#endregion

#region class.cpp ----------------------------------------------------------------------------------------

echo \
'#include "'../inc/$2'.hpp" 

'$2'::'$2'() : value(0) {
    std::cout << "\033[38;5;228mDefault constructor called\033[0m" << std::endl;
}

'$2'::'$2'(const '$2'& other) : value(other.value) {
    std::cout << "\033[38;5;228mCopy constructor called\033[0m" << std::endl;
}

'$2'& '$2'::operator=(const '$2'& other) {
    value = other.value;
    std::cout << "\033[38;5;228mCopy assignment operator called\033[0m" << std::endl;
    return *this;
}

'$2'::~'$2'() {
    std::cout << "\033[38;5;228mDestructor called\033[0m" << std::endl;
}' > ./src/$2.cpp

#endregion

# region main.cpp ----------------------------------------------------------------------------------------
echo \
'#include <iostream>
#include "'../inc/$2'.hpp"

int main() {
    '$2' obj;

    std::cout << "Hello, World!" << std::endl;

    return 0;
}' > ./src/main.cpp

#endregion