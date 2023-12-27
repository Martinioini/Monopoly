#include "Player.h"

class PlayerNPC : Player
{
    bool pay(int price) override
    {
        srand (((unsigned) time(NULL)));
        int random = 1 + (rand() % 4);
        if(random == 1)
    }

    bool buyHouse() override
    {

    }
}

