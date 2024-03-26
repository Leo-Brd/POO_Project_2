#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class Weapon{
    private:

        char name[20];
        int damage;

    public:

        Weapon() : name("None"), damage(0) {}

        Weapon(const char newName[], int newDamage) : damage(newDamage) {
            strncpy(name, newName, sizeof(name) - 1); 
            name[sizeof(name) - 1] = '\0'; 
        }

        const char* getName() const { return name; }
        int getDamage() const { return damage; }

};

class RPCharacter{
    private:

        char name[15];
        int level;
        int xp_points;
        int hp;
        std::vector<Weapon> weapon_list;
        int weapon_quantity;
        Weapon weapon_used;
        bool is_dead;

    public:

        RPCharacter(const char newName[]) {
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

        };

        const char* getName() const { return name; }
        void setName(const char* newName) {
            strncpy(name, newName, sizeof(name) - 1); 
            name[sizeof(name) - 1] = '\0'; 
        };

        void apply_damage(int damage_value){
            hp -= damage_value;
            std::cout << "Le Joueur " << getName() << " perd " << damage_value << " hp !" << std::endl;
            if (hp <= 0){
                std::cout << "Le Joueur " << getName() << " est mort !" << std::endl;
                is_dead = true;
                hp = 0;
            };
        };

        Weapon get_weapon(int indice){
            if (weapon_quantity == 0){
                weapon_quantity += 1;
                weapon_list.clear();
                std::cout << "Le Joueur " << getName() << " se muni de ses poings" << std::endl;
                if (level == 1){
                    weapon_list.push_back(Weapon("Hand", 1));
                }else{
                    weapon_list.push_back(Weapon("Hand", level/2));
                };
                weapon_used = weapon_list[0];
                return weapon_list[0];            
            };
            
            if ( indice > -1 || indice < 10){
                if (std::strcmp(weapon_list[indice].getName(), "None") == 0) {
                    int last_weapon_index = -1;
                    for (int i = 0; i < 10; ++i) {
                        if (std::strcmp(weapon_list[i].getName(), "None") == 0) {
                            last_weapon_index = i;
                        }
                    }
                    if (last_weapon_index != -1) {return weapon_list[last_weapon_index];}

                } else {
                    return weapon_list[indice];
                }
                std::cout << "Le Joueur " << getName() << " sort son arme " << weapon_list[indice].getName() << std::endl;
            }
        };

        void Attack(RPCharacter& targetCharacter) {
            std::cout << "Le Joueur " << getName() << " attaque le joueur " << targetCharacter.getName() <<  std::endl;
            int damage = weapon_used.getDamage(); 
            targetCharacter.apply_damage(damage); 
            xp_points += damage;
        };

        void store_weapon(Weapon weapon){
            if (weapon_quantity == 10){
                weapon_list.pop_back();
            };
            weapon_list.push_back(weapon);
            weapon_quantity += 1;
            std::cout << "Le Joueur " << getName() << " ajoute l'arme " << weapon.getName() << " à son inventaire !" << std::endl;
        };

        void switch_weapon(int indice){
            if ( indice < 0 || indice > 9){
                std::cout << "Veuillez rentrer un emplacement valide" << std::endl;
                return;
            };

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
        };

        void drink_potion(int value){
            hp += value;
            std::cout << "Le Joueur " << getName() << " se régénère de " << value << " hp !" << std::endl;
            if ( hp > 100 ){
                hp = 100;
                std::cout << "Le Joueur " << getName() << " est full vie " << std::endl;
            }
        };

};



int main(void){

    // Création des deux joueurs
    RPCharacter Noamus = RPCharacter("Noamus");
    RPCharacter Antoinus = RPCharacter("Antoinus");

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

    // Antoinus est pris au dépourvu mais trouve un fléaux géant à ses pieds qu'il ramasse
    Antoinus.store_weapon(Weapon("Fléaux Géant", 30));

    // Se trouvant à distance, Antoinus ne peut pas porter de coup à Noamus. 
    // Ce dernier en profite pour sortir sa baguette magique et lancer une attaque remplie de fourberie
    Noamus.switch_weapon(2);
    Noamus.Attack(Antoinus);

    // Après avoir encaissé cette attaque farfelue, Antoinus court en direction de Noamus et le frappe avec son fléaux
    Antoinus.switch_weapon(1);
    Antoinus.Attack(Noamus);

    // Noamus recule et brandit une potion de shield bleue tah fortnite prime qu'il engloutit
    Noamus.drink_potion(50);

    // Cela poussa Antoinus à user de la malveillance max
    // La malice ne suffit pas à Noamus pour stopper la série d'attaque d'Antoinus 
    std::cout << "MALVEILLANCE MAX !!!!!!!!!!!!" << std::endl;
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);
    Antoinus.Attack(Noamus);

    // Antoinus crie de rage après avoir éteint le petit lutin espiègle Noamus






};