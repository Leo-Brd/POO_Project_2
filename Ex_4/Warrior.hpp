#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "RPCharacter.hpp"

class Warrior : public RPCharacter {
private:
    int strength;

public:
    Warrior() : RPCharacter("UnnamedWarrior", 150), strength(50) {}
    Warrior(const char newName[]) : RPCharacter(newName), strength(50) {}

    int getStrength() const { return strength; }

};

#endif