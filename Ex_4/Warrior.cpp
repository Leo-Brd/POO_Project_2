#include "Warrior.hpp"

Warrior::~Warrior() {
    std::cout << "Le guerrier " << getName() << " a été détruit." << std::endl;
}