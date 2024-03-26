#include "animals.hpp"

void Animal::play() {
    std::cout << "L'animal joue" << std::endl;
};

void Animal::eat() {
    std::cout << "L'animal mange" << std::endl;
};

void Cat::meow() {
    std::cout << "Le chat miaule" << std::endl;
};

void Dog::bark() {
    std::cout << "Le chien aboie" << std::endl;
};

void Dog::eat() {
    std::cout << "Le chien mange salement" << std::endl;
};