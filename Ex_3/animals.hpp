#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include "human.hpp"

class Animal {
    public:
        virtual void play();
        virtual void eat();
        virtual void play_with_human(Human &h);
};

class Cat : public Animal {
    public:
        void play();
        void meow();
        //void play_with_human(Human &h);
};

class Dog : public Animal {
    public:
        void play();
        void bark();
        void eat();
        void play_with_human(Human &h);
};

#endif