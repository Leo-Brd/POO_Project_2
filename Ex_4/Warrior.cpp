#include "Warrior.hpp"

Warrior::Warrior(const char newName[]) : RPCharacter(newName) {
    strength = 100;
    std::cout << "Le guerrier " << getName() << " apparait " << std::endl;
}

int Warrior::getStrength() const {
    return strength;
}

void Warrior::setStrength(int newStrength) {
    strength = newStrength;
}

void Warrior::useWeapon() {
    std::cout << "Le guerrier " << getName() << " utilise son arme !" << std::endl;
}