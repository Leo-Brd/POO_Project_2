#include <iostream>
#include "animals.hpp"
#include "human.hpp"


void animal_day(Animal &animal, Human &human) {
    animal.eat();
    animal.play();
    animal.eat();
    animal.play_with_human(human);
}

int main(){
    Cat c; Dog d;
    Human my_human;

    std::cout << "Journée typique pour le chat :" << std::endl;
    animal_day(c, my_human);

    std::cout << "\nJournée typique pour le chien :" << std::endl;
    animal_day(d, my_human);

    return 0;
}