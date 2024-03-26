#include "Weapon.hpp"

Weapon::Weapon() : damage(0) {
    strncpy(name, "None", sizeof(name) - 1); 
    name[sizeof(name) - 1] = '\0'; 
}

Weapon::Weapon(const char newName[], int newDamage) : damage(newDamage) {
    strncpy(name, newName, sizeof(name) - 1); 
    name[sizeof(name) - 1] = '\0'; 
}

const char* Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}