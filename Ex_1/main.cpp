#include <iostream>

class Animal {

    public:
        void eat();
        void play();

};

class Cat : public Animal{

    public:
        void meow();

};

class Dog : public Animal{

    public:
        void bark();
};

int main(){

    Cat c; Dog d;
    c.play(); d.play();
    c.meow(); d.bark();
}