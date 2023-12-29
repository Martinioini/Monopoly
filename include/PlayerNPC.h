#ifndef PLAYERNPC_H
#define PLAYERNPC_H

#include "Player.h"
#include <iostream>
#include <string>


class PlayerNPC : public Player
{
    public:

        PlayerNPC(int index);

        bool buyCell(int price, Cell cell) override;

        bool buyHouse(Cell cell) override;
};



#endif //PLAYERNPC_H