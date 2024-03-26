#!/bin/bash

# Compilation
g++ -std=c++20 -fmodules-ts -c animals.cpp -o animals.o
g++ -std=c++20 -fmodules-ts -c main.cpp -o main.o

# Édition de liens
g++ -std=c++20 -fmodules-ts animals.o main.o -o executable

# Exécution
./executable