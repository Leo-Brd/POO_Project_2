#!/bin/bash

# Compilation des fichiers source en fichiers objets
g++ -std=c++20 -fmodules-ts -c RPCharacter.cpp -o RPCharacter.o
g++ -std=c++20 -fmodules-ts -c Warrior.cpp -o Warrior.o
g++ -std=c++20 -fmodules-ts -c Weapon.cpp -o Weapon.o
g++ -std=c++20 -fmodules-ts -c Wizard.cpp -o Wizard.o
g++ -std=c++20 -fmodules-ts -c main.cpp -o main.o

# Édition de liens pour créer l'exécutable
g++ -std=c++20 -fmodules-ts RPCharacter.o Warrior.o Weapon.o Wizard.o main.o -o executable

# Exécution de l'exécutable
./executable
