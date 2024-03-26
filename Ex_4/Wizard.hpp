#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "RPCharacter.hpp"

class Wizard : public RPCharacter {
private:
    int mana;

public:
    Wizard() : RPCharacter("UnnamedWizard") {
        std::cout << "Un nouveau sorcier non nommé a été créé !" << std::endl;
    }
    Wizard(const char newName[]) : RPCharacter(newName), mana(100) {}

    int getMana() const { return mana; }

    void print() const {
        RPCharacter::print();
        std::cout << "Mana: " << mana << std::endl;
    }

    void receive_damage(int damage_value) override {
        int new_damage = damage_value / 2;
        hp -= new_damage;
        std::cout << "Le Joueur " << getName() << " perd " << new_damage << " hp !" << std::endl;
        if (hp <= 0) {
            std::cout << "Le Joueur " << getName() << " est mort !" << std::endl;
            is_dead = true;
            hp = 0;
        }
    }

    ~Wizard();

};

#endif