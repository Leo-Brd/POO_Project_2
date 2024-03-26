#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <cstring>

class Weapon {
private:
    char name[20];
    int damage;

public:
    Weapon();
    Weapon(const char newName[], int newDamage);
    const char* getName() const;
    int getDamage() const;
};

#endif