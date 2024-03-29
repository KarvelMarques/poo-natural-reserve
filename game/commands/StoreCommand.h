﻿//
// Created by duarte on 09-12-2022.
//

#ifndef POO_NATURAL_RESERVE_STORECOMMAND_H
#define POO_NATURAL_RESERVE_STORECOMMAND_H
#include "../models/commands/DefaultCommand.h"

class StoreCommand: public DefaultCommand {
public:
    StoreCommand(Game* game,std::vector<std::string> args): DefaultCommand(game,args){}
    void execute() override;
};



#endif //POO_NATURAL_RESERVE_STORECOMMAND_H
