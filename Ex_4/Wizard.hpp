#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "RPCharacter.hpp"

class Wizard : public RPCharacter {
private:
    int mana;

public:
    Wizard(const char newName[]) : RPCharacter(newName), mana(100) {}

    int getMana() const { return mana; }

};

#endif