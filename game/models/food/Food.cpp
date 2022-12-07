//
// Created by duarte on 10-11-2022.
//

#include <iostream>
#include "Food.h"

void Food::incrementLifeTick() {

}


void Food::isFoodAvailable() {

}

void Food::defineRandomPosition(int maxRow, int maxLine) {
    int row = rand() % (maxRow);
    int col = rand() % (maxLine);
    this->position.row = row;
    this->position.column = col;
}

Food::Food() {
    this->id = Entity::defineNewId();
}

void Food::definePosition(int row, int line) {
    this->position.row = row;
    this->position.column = line;
}

void Food::display() {
    std::cout << "[" + std::to_string(this->id)+ "] [" + std::to_string(this->position.row) + std::to_string(this->position.column) + "] " + this->identifierEmoji + " Toxicity: " + std::to_string(this->toxicity) << std::endl;
}