#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "RPCharacter.hpp"

class Wizard : public RPCharacter {
private:
    int mana;

public:
    Wizard(const char newName[]);
    int getMana() const;
    void setMana(int newMana);
    void castSpell();
};

#endif