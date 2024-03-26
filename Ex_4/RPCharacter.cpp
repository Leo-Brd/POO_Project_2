#include "RPCharacter.hpp"
#include <cstring>

RPCharacter::RPCharacter(const char newName[]) {
    strncpy(name, newName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    level = 1;
    xp_points = 0;
    hp = 100;
    weapon_quantity = 0;
    weapon_list.push_back(Weapon());
    weapon_list.resize(10);
    weapon_used = Weapon();
    is_dead = false;
    std::cout << "Le Joueur " << getName() << " apparait " << std::endl;
}

RPCharacter::RPCharacter(const char newName[], int newhp){
    strncpy(name, newName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    hp = newhp;
};

const char* RPCharacter::getName() const {
    return name;
}

void RPCharacter::setName(const char* newName) {
    strncpy(name, newName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void RPCharacter::apply_damage(int damage_value) {
    hp -= damage_value;
    std::cout << "Le Joueur " << getName() << " perd " << damage_value << " hp !" << std::endl;
    if (hp <= 0) {
        std::cout << "Le Joueur " << getName() << " est mort !" << std::endl;
        is_dead = true;
        hp = 0;
    }
}

Weapon RPCharacter::get_weapon(int indice) {
    if (weapon_quantity == 0) {
        weapon_quantity += 1;
        weapon_list.clear();
        std::cout << "Le Joueur " << getName() << " se muni de ses poings" << std::endl;
        if (level == 1) {
            weapon_list.push_back(Weapon("Hand", 1));
        } else {
            weapon_list.push_back(Weapon("Hand", level / 2));
        }
        weapon_used = weapon_list[0];
        return weapon_list[0];
    }

    if (indice > -1 || indice < 10) {
        if (std::strcmp(weapon_list[indice].getName(), "None") == 0) {
            int last_weapon_index = -1;
            for (int i = 0; i < 10; ++i) {
                if (std::strcmp(weapon_list[i].getName(), "None") == 0) {
                    last_weapon_index = i;
                }
            }
            if (last_weapon_index != -1) {
                return weapon_list[last_weapon_index];
            }
        } else {
            return weapon_list[indice];
        }
        std::cout << "Le Joueur " << getName() << " sort son arme " << weapon_list[indice].getName() << std::endl;
    }
}

void RPCharacter::Attack(RPCharacter& targetCharacter) {
    std::cout << "Le Joueur " << getName() << " attaque le joueur " << targetCharacter.getName() << std::endl;
    int damage = weapon_used.getDamage();
    targetCharacter.apply_damage(damage);
    xp_points += damage;
}

void RPCharacter::store_weapon(Weapon weapon) {
    if (weapon_quantity == 10) {
        weapon_list.pop_back();
    }
    weapon_list.push_back(weapon);
    weapon_quantity += 1;
    std::cout << "Le Joueur " << getName() << " ajoute l'arme " << weapon.getName() << " à son inventaire !" << std::endl;
}

void RPCharacter::switch_weapon(int indice) {
    if (indice < 0 || indice > 9) {
        std::cout << "Veuillez rentrer un emplacement valide" << std::endl;
        return;
    }

    if (std::strcmp(weapon_list[indice].getName(), "None") == 0) {
        int last_weapon_index = -1;
        for (int i = 0; i < 10; ++i) {
            if (std::strcmp(weapon_list[i].getName(), "None") == 0) {
                last_weapon_index = i;
            }
        }

        if (last_weapon_index != -1) {
            weapon_used = weapon_list[last_weapon_index];
            std::cout << "Arme switchée à l'emplacement " << last_weapon_index << std::endl;
        } else {
            std::cout << "La liste des armes est vide" << std::endl;
        }
    } else {
        weapon_used = weapon_list[indice];
        std::cout << "Arme switchée à l'emplacement " << indice << std::endl;
    }
}

void RPCharacter::drink_potion(int value) {
    hp += value;
    std::cout << "Le Joueur " << getName() << " se régénère de " << value << " hp !" << std::endl;
    if (hp > 100) {
        hp = 100;
        std::cout<< "Le Joueur " << getName() << " est full vie " << std::endl;
    }
}

void RPCharacter::print() const {
    std::cout << "Nom: " << name << std::endl;
    std::cout << "Niveau: " << level << std::endl;
    std::cout << "Points d'expérience: " << xp_points << std::endl;
    std::cout << "Points de vie: " << hp << std::endl;
    std::cout << "Nombre d'armes: " << weapon_quantity << std::endl;
    std::cout << "Arme utilisée: " << weapon_used.getName() << std::endl;
    std::cout << "Est mort: " << (is_dead ? "Oui" : "Non") << std::endl;
}

RPCharacter::~RPCharacter() {
    std::cout << "Le personnage " << name << " a été détruit." << std::endl;
}

void may_delete(RPCharacter* c) {
    delete c;
}