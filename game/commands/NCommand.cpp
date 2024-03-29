﻿//
// Created by duarte on 10-12-2022.

#include <iostream>
#include "NCommand.h"
#include "../utils/utils.h"
#include "KillCommand.h"
#include "NoFoodCommand.h"
#include <chrono>
#include <thread>

void NCommand::instantExecution() {
    //iterate the animals executing the do_iteration function
    std::cout << "  > Executing one instant for all the animals " << std::endl;
    Node<Animal> * current = this->game->animals;
    std::vector<int> animalsToDelete = {};
    while(current != NULL){
        current->value->do_iteration(game);
        if(current->value->currentHP <= 0){
            std::cout << "      > Animal died: ";
            current->value->display();
            animalsToDelete.push_back(current->value->id);
        }
        current = current->next;
    }

    for(int i = 0; i < animalsToDelete.size(); i++){
        KillCommand::deleteAnimalFromList(game,animalsToDelete[i]);
    }

    //iterate the food executing the do_iteration function
    std::cout << "  > Executing one instant for all the foods " << std::endl;
    Node<Food> * currentFood = this->game->foods;
    std::vector<int> foodsToDelete = {};
    while(currentFood != NULL){
        currentFood->value->do_iteration(game);
        Food * cFoodValue = currentFood->value;

        if(cFoodValue->currentIterations >= cFoodValue->maxIterations){
            std::cout << "      > Food died: ";
            cFoodValue->display();
            foodsToDelete.push_back(cFoodValue->id);
        }
        currentFood = currentFood->next;
    }

    for(int y = 0; y < foodsToDelete.size(); y++){
        NoFoodCommand::deleteFoodFromList(game,foodsToDelete[y]);
    }
    std::cout << "  > Instant completed successfully" << std::endl;
}

//TODO: Implement the n command
void NCommand::execute() {
    if(args.size() == 1){
        std::cout << "  > Executing the n command" << std::endl;
        this->instantExecution();
    }else if (args.size() == 2){
        if(isNumber(args[1])){
            std::string times = args[1];
            std::cout << "  > Executing the n command times: " +  times << std::endl;
            for(int i = 0; i < std::stoi(times); i++){
                this->instantExecution();
            }
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else if(args.size() == 3){
        if(isNumber(args[1]) && isNumber(args[2])){
            std::string times = args[1];
            std::string sleep = args[2];
            std::cout << "  > Executing the n command times: " +  times + " with sleep cool down: " + sleep << std::endl;
            for(int i = 0; i < std::stoi(times); i++){
                this->instantExecution();
                std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(sleep) * 1000));
            }
        }else{
            std::cout << "  > Sorry, we couldn't execute the n command, when passing arguments they should be numbers for the n command" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the n command should contain, no args, 1 or 2 args, example: n, n<N>, n <N> <P>" << std::endl;
    }
}
