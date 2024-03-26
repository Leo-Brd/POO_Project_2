#ifndef RPCHARACTER_HPP
#define RPCHARACTER_HPP

#include "Weapon.hpp"
#include <iostream>
#include <vector>

class RPCharacter {
protected:
    char name[15];
    int level;
    int xp_points;
    int hp;
    std::vector<Weapon> weapon_list;
    int weapon_quantity;
    Weapon weapon_used;
    bool is_dead;

public:
    ~RPCharacter();
    RPCharacter(const char newName[]);
    RPCharacter(const char newName[], int newhp);
    const char* getName() const;
    void setName(const char* newName);
    void apply_damage(int damage_value);
    Weapon get_weapon(int indice);
    void Attack(RPCharacter& targetCharacter);
    void store_weapon(Weapon weapon);
    void switch_weapon(int indice);
    void drink_potion(int value);
    void print() const;
    void may_delete(RPCharacter* c)
};

#endif