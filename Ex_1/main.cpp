#include <iostream>
/*
class Animal {

    public:
        void play(){
            std::cout << "L'animal joue" << std::endl;
        };

};

class Cat : public Animal{

    public:
        void meow(){
            std::cout << "Le chat miaule" << std::endl;
        };

};

class Dog : public Animal{

    public:
        void bark(){
            std::cout << "Le chien aboie" << std::endl;
        };
};
*/

int main(){

    Cat c; Dog d;
    c.play(); d.play();
    c.meow(); d.bark();
}