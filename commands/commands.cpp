//
// Created by duarte on 11-11-2022.
//
#include <iostream>
#include "commands.h"
#include "../utils/utils.h"
#include "../game/game/Game.h"

void exec_command_animal(std::vector<std::string> args){
    std::cout << "  > Executing the animal command" << std::endl;
    //displayStringsList(args);

    if(args.size() < 2){
        std::cout << "  > Invalid command provided, the animal command must contain at least 1 argument <specie: c / o / l / g / m> or <specie: c / o / l / g / m> <line> <column>" << std::endl;
    }else if(args.size() == 2){
        std::cout << "  > Spawning the specie of type " + args[1] +  " in a random position" << std::endl;
    }else if(args.size() == 4){
        std::string line = args[2];
        std::string column = args[3];

        if(isNumber(line) && isNumber(column)){
            std::cout << "  > Spawning the specie of type " + args[1] +  " in the position: l:" + line + " c:" + column << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the animal command should contain the position and line arguments as integers and not characters" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the animal command must contain at least 1 argument <specie: c / o / l / g / m> or <specie: c / o / l / g / m> <line> <column>" << std::endl;
    }

}
void exec_command_kill(std::vector<std::string> args) {
    std::cout << "  > Executing the kill command" << std::endl;


    if(args.size()== 2){
        if(isNumber(args[1])){
            //kill an entity id on args[1];
            std::cout << "  > killing the animal with id: " + args[1] << std::endl;
        }else{
            std::cout << "  > Invalid command provided, the id must be an integer" << std::endl;
        }

    }else if (args.size() == 3){
        //kill entities at a given position args[1] and args[2]
        std::string line = args[1];
        std::string column = args[2];
        if (isNumber(line) && isNumber(column)) {
            std::cout << "  > killing the animal in the position: l: " + args[1] + " c:" + args[2] << std::endl;
        } else {
            std::cout << "  > Invalid command provided, the line and columns arguments must be integers" << std::endl;
        }
    }else{
        std::cout << "  > Invalid command provided, the kill command can be kill <line> <column> or , kill <id> " << std::endl;
    }
}

void exec_command_food(std::vector<std::string> args){
    std::cout << "  > Executing the food command" << std::endl;
    // food <tipo: r / t / b / a> <linha> <coluna>
    //food <tipo: r / t / b / a>
    bool validFood = false;
    if ( args.size() == 2 ) {
        for( const auto &item : allowedFoodTypes){
            if(args[1]== item) {
                validFood = true;
                std::cout << "Spawning " + item + " in a random position "<< std::endl;
            }
        }
        if(validFood == false){
            std::cout << " Please insert valid a type of food" << std::endl;
        }
    }
    else if(args.size() == 4) {
        for (const auto &item: allowedFoodTypes) {
            if (args[1] == item) {
                validFood = true;
                if (isNumber(args[2]) && isNumber(args[3])) {
                    std::cout << "  > Spawning " + args[1] + " in the position: l: " + args[2] + " c:" + args[3]  << std::endl;
                }
            }
        }
        if (validFood == false) {
            std::cout << " Please insert valid a type of food or integer values on the line/column" << std::endl;
        }
    }else{
        std::cout << " Food command should look like: (food <tipo: r / t / b / a> <linha> <coluna>  or (food <tipo: r / t / b / a>)" << std::endl;
    }
}


void exec_command_feed(std::vector<std::string> args) {
    std::cout << "  > Executing the feed command" << std::endl;
// feedid <ID> <pontos nutritivos> <pontos de toxicidade>
    bool validAnimal = false;
    if (args.size() == 5) {
        for (const auto &item: allowedAnimalsTypes) {
            if (args[1] == item) {
                validAnimal = true;
                if (isNumber(args[2]) && isNumber(args[3]) && isNumber(args[4])) {
                    std::cout<< "Feeding animal at line:" + args[1] + " and column: " + args[2] + "blessing him with " + args[3] + " points of health and " + args[4] + " points of toxicity" << std::endl;
                } else if (args.size() == 4) {
                    if (isNumber(args[1]) && isNumber(args[2]) && isNumber(args[3])) {
                        std::cout << "Feeding animal with id: " + args[1] + "blessing him with" + args[2] +" points of health and" + args[3] + "points of toxicity" << std::endl;
                    }
                }
                if (args.size() < 4) {
                    std::cout<< "Please insert command Feed with the right format: (feed <linha> <coluna> <pontos nutritivos> <pontos de toxicidade>) or feedid <ID> <pontos nutritivos> <pontos de toxicidade> "<< std::endl;
                }
            }
// feed <linha> <coluna> <pontos nutritivos> <pontos de toxicidade>
        }
    }
}
void exec_command_feedid(std::vector<std::string> args){
    std::cout << "  > Executing the feedid command" << std::endl;
}
void exec_command_nofood(std::vector<std::string> args){
    std::cout << "  > Executing the nofood command" << std::endl;
}
void exec_command_empty(std::vector<std::string> args){
    std::cout << "  > Executing the empty command" << std::endl;
}
void exec_command_see(std::vector<std::string> args){
    std::cout << "  > Executing the see command" << std::endl;
}
void exec_command_info(std::vector<std::string> args){
    std::cout << "  > Executing the info command" << std::endl;
}
void exec_command_n(){
    std::cout << "  > Executing the n command" << std::endl;
}
void exec_command_n(std::vector<std::string> args){
    std::cout << "  > Executing the n command with args" << std::endl;
}
void exec_command_anim(Game* game){
    std::cout << "  > Executing the anim command" << std::endl;
    for (const auto &item: game->animals){
        std::cout << "      [" + std::to_string(item.id) + "]" +  " " + item.identifier + " HP: " + std::to_string(item.health) << std::endl;
    }
}
//TODO: required for the first meta
void exec_command_visanim(){
    std::cout << "  > Executing the visanim command" << std::endl;
}
void exec_command_store(std::vector<std::string> args){
    std::cout << "  > Executing the store command" << std::endl;
}
void exec_command_restore(std::vector<std::string> args){
    std::cout << "  > Executing the restore command" << std::endl;
}
void exec_command_load(std::vector<std::string> args){
    std::cout << "  > Executing the load command" << std::endl;
}

//TODO: required for the first meta
void exec_command_slide(std::vector<std::string> args){
    std::cout << "  > Executing the slide command" << std::endl;
}
