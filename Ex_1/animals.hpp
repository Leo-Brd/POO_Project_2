#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>

class Animal {
public:
    void play();
    void eat();
};

class Cat : public Animal {
public:
    void meow();
};

class Dog : public Animal {
public:
    void bark();
    void eat();
};

#endif 