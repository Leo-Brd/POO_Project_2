#include "Wizard.hpp"

Wizard::Wizard(const char newName[]) : RPCharacter(newName) {
    mana = 100;
    std::cout << "Le sorcier " << getName() << " apparait " << std::endl;
}

int Wizard::getMana() const {
    return mana;
}

void Wizard::setMana(int newMana) {
    mana = newMana;
}

void Wizard::castSpell() {
    if (mana >= 20) {
        std::cout << "Le sorcier " << getName() << " lance un sort !" << std::endl;
        mana -= 20;
    } else {
        std::cout << "Le sorcier " << getName() << " n'a pas assez de mana pour lancer un sort !" << std::endl;
    }
}