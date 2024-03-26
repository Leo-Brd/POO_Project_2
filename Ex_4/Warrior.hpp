#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "RPCharacter.hpp"

class Warrior : public RPCharacter {
private:
    int strength;

public:
    Warrior(const char newName[]);
    int getStrength() const;
    void setStrength(int newStrength);
    void useWeapon();
};

#endif