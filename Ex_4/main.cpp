#include <iostream>
#include "RPCharacter.hpp"
#include "Weapon.hpp"
#include "Wizard.hpp"
#include "Warrior.hpp"

int main() {

    Wizard gandalf("Gandalf");

    Warrior* guerrier = new Warrior("Guerrier");

    Warrior may_delete(*guerrier);

    // Création des deux joueurs
    Warrior Noamus("Noamus");
    Wizard Antoinus("Antoinus");

    // Les deux joueurs sortent leurs poings
    Noamus.get_weapon(0);
    Antoinus.get_weapon(0);

    // Noamus est en possession d'une sarbacane malicieuse ainsi que d'une baguette magique
    Noamus.store_weapon(Weapon("Sarbacane", 10));
    Noamus.store_weapon(Weapon("Baguette magique", 20));

    // Les deux joueurs se donnent quelques coups
    Noamus.Attack(Antoinus);
    Antoinus.Attack(Noamus);
    Noamus.Attack(Antoinus);
    Antoinus.Attack(Noamus);

    // Noamus brandit sa sarbacane et use de sa malice en tirant deux épines aux pieds d'Antoinus
    Noamus.switch_weapon(1);
    Noamus.Attack(Antoinus);
    Noamus.Attack(Antoinus);

    // Antoinus est pris au dépourvu mais trouve un fléau géant à ses pieds qu'il ramasse
    Antoinus.store_weapon(Weapon("Fléau Géant", 30));

    // Se trouvant à distance, Antoinus ne peut pas porter de coup à Noamus. 
    // Ce dernier en profite pour sortir sa baguette magique et lancer une attaque remplie de fourberie
    Noamus.switch_weapon(2);
    Noamus.Attack(Antoinus);

    // Après avoir encaissé cette attaque farfelue, Antoinus court en direction de Noamus et le frappe avec son fléau
    Antoinus.switch_weapon(1);
    Antoinus.Attack(Noamus);

    // Noamus recule et brandit une potion de shield bleue tah fortnite prime qu'il engloutit
    Noamus.drink_potion(50);

    // Cela pousse Antoinus à user de la malveillance max
    // La malice ne suffit pas à Noamus pour stopper la série d'attaque d'Antoinus 
    std::cout << "MALVEILLANCE MAX !!!!!!!!!!!!" << std::endl;
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);

    // Antoinus crie de rage après avoir éteint le petit lutin espiègle Noamus

    return 0;
}