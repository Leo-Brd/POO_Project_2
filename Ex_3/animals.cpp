#include "animals.hpp"
#include "human.hpp"

class Human;

void Animal::play() {
    std::cout << "L'animal joue" << std::endl;
}

void Animal::eat() {
    std::cout << "L'animal mange" << std::endl;
}

void Animal::play_with_human(Human &h) {
    std::cout << "L'animal joue avec un humain" << std::endl;
}

void Cat::play() {
    std::cout << "Le chat joue" << std::endl;
}

void Cat::meow() {
    std::cout << "Le chat miaule" << std::endl;
}
/*
void Cat::play_with_human(Human &h) {
    std::cout << "Les chats sont autonomiaous" << std::endl;
}
*/

void Dog::play() {
    std::cout << "Le chien joue" << std::endl;
}

void Dog::bark() {
    std::cout << "Le chien aboie" << std::endl;
};

void Dog::eat() {
    Animal::eat();
    std::cout << "Le chien mange salement" << std::endl;
}

void Dog::play_with_human(Human &h) {
    std::cout << "Le chien joue avec un humain" << std::endl;
}

