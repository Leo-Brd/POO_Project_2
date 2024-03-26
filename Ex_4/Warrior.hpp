#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "RPCharacter.hpp"

class Warrior : public RPCharacter {
private:
    int strength;

public:
    Warrior() : RPCharacter("UnnamedWarrior", 150), strength(50) {
        std::cout << "Un nouveau guerrier non nommé a été créé !" << std::endl;
    }
    Warrior(const char newName[]) : RPCharacter(newName), strength(50) {}

    int getStrength() const { return strength; }

    void print() const {
        RPCharacter::print();
        std::cout << "Force: " << strength << std::endl;
    }

    ~Warrior();


};

#endif