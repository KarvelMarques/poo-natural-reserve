//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_ANIMAL_H
#define POO_NATURAL_RESERVE_ANIMAL_H


#include <string>
#include "../Position.h"

//TODO: add the shared Id to the animal
class Animal {
private:
    int currentLifetime;
public:
    std::string identifier;
    Position position = {0,0};
    int weight;
    int hunger;
    int health;
    int angryLevel;
    int maxLifetime;
    Animal();

    //TODO: implement the function that feeds the current animal receiving a certain value
    void feedAnimal();

    //TODO: this function will contain all the logic representing the instant
    virtual void triggerInstant();

    //TODO: this function should be implemented by each child animal class
    virtual void move();
    //TODO: this function should be implemented by the child animals and verified if every animal have the reproduce function
    virtual void reproduce();
    //TODO: this function should be implemented from the child classes implementing the logic when perceiving food and other animals
    virtual void perceive();

    int getCurrentLifetime();

    void defineRandomPosition(int maxRow,int maxLine);

};


#endif //POO_NATURAL_RESERVE_ANIMAL_H
