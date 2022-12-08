//
// Created by duarte on 10-11-2022.
//

#include <limits>
#include <fstream>
#include <csignal>
#include "../user_interface/userInterface.h"
#include "GameService.h"
#include "../models/animal/Rabbit.h"
#include "../models/animal/Sheep.h"
#include "../models/food/Grass.h"
#include "../utils/utils.h"
#include "../models/animal/Fox.h"
#include "../models/animal/Kangaroo.h"
#include "../models/animal/Wolf.h"
#include "../models/food/Carrot.h"
#include "../models/food/Blueberries.h"
#include "../models/food/Body.h"
#include "../models/food/Beef.h"
#include "../models/commands/Command.h"

using namespace std;

void GameService::defineNaturalReserveConfiguration() {
    int length = 0;
    int height = 0;
    bool failedValidations = false;

    cout << "Please provide the length of the natural reserve, value between 5-500" << endl;
    cout << "Length: ";
    cin >> length;

    if(!std::cin.good())
        failedValidations = true;

    if(!failedValidations){
        cout << "Please provide the height of the natural reserve, value between 5-500" << endl;
        cout << "Height: ";
        cin >> height;
    }

    if(!std::cin.good())
       failedValidations = true;

    if(failedValidations){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << " > Something went wrong defining the values of the natural reserve" << endl;
        cout << " > Please provide them again..." << endl;
        this->defineNaturalReserveConfiguration();
    }else{
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

        this->game.configuration.setMatrixSize(height,length);
        this->game.configuration.displayMatrixSize();
    }
}

void GameService::initializeMatrix() {
    int x,y;
    for( x = 0; x < this->game.configuration.size.cols; x++){
        vector<MatrixCell> col = {};
        for(y = 0; y < this->game.configuration.size.rows; y++){
            col.push_back(MatrixCell(x,y));
            //cout << " > created cell -> x:" + to_string(x) + " y: " + to_string(y) << endl;
        }
        this->game.matrix.push_back(col);
    }
    //cout << " > num rows configured: " + to_string(this->models.matrixGetNumRows()) + " cols: " + to_string(this->models.matrixGetNumColumns()) << endl;
}

void GameService::readConstantsFile() {
    std::vector<std::string> commands;
    FILE *f = NULL;

    std::string currentCommand;
    fstream newfile;
    string fileName = "constantes.txt";

    newfile.open(fileName,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        std::cout << "============================| CONSTANTS  -  FILE | ============================ " << std::endl;

        cout << "We have detected the a configuration file, executing.." << endl;
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            commands.push_back(tp);
        }
        newfile.close(); //close the file object.
    }

    if(commands.size() > 0){

        //do something with the commands from the file
        for (string item: commands){

            if(item.size() > 1){
                cout << "   > executing configuration setting: " + item << endl;
                vector<string> args = Command::getArguments(item);

                if(args.size() == 2){
                    //handling definitions for animals
                    if(args[0] == "SSheep"){
                        if(isNumber(args[1])){
                            Sheep::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the sheep configuration" << endl;
                        }
                    }
                    else if(args[0] == "SRabbit"){
                        if(isNumber(args[1])){
                            Rabbit::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the sheep configuration" << endl;
                        }
                    }
                    else if(args[0] == "SFox"){
                        if(isNumber(args[1])){
                            Fox::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the fox configuration" << endl;
                        }
                    }
                    else if(args[0] == "SKangaroo"){
                        if(isNumber(args[1])){
                            Kangaroo::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the kangaroo configuration" << endl;
                        }
                    }
                    else if(args[0] == "SWolf"){
                        if(isNumber(args[1])){
                            Wolf::maxHP = stoi(args[1]);
                        }else{
                            cout << "   > Invalid second parameter detected for the wolf configuration" << endl;
                        }
                    }
                }else{
                    cout << "   > line detected with ony with one argument" << endl;
                }
            }else{
                cout << "   > empty line configuration detected " << endl;
            }
        }

        std::cout << "==========================| END OF CONSTANTS FILE | =========================== " << std::endl;

    }
}

void GameService::initialize() {
    std::cout << "           \U0001f334 \U0001f334 \U0001f334 Welcome to the natural reserve \U0001f334 \U0001f334 \U0001f334 " << std::endl;
    std::cout << "========================================================================" << std::endl;
    this->defineNaturalReserveConfiguration();
    //set the matrix with the default values
    this->initializeMatrix();
    //required to turn the spawn of the entities on random places always
    srand((unsigned)time(NULL));

    readConstantsFile();

    std::cout << "===============================================================================" << std::endl;
    std::cout << " > The natural reserve has been initialized with the following animals and foods: " << std::endl;
    this->game.displayFoods();
    this->game.displayAnimals();
    std::cout << "===============================================================================" << std::endl;

    displayAnimals(this->game);
    displayNaturalReserve(this->game);
    Command::handleCommands(&this->game);
}
