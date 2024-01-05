#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Cell.h"
#include <iostream>
#include <string>

class GameField
{
    private:

        static constexpr int mapLength = 28;

        Cell path[mapLength];    //mappa

    public:
    
        GameField();  

        void generatePath();     //generate the random number of cells in the path following constraints

        void printMap();

        void setCell();

        void removePlayerProperties(int playerIndex);

        void setPlayerCell(int position, int playerIndex);

        void removePlayer(int position, int playerIndex);

        Cell* getCell(int index);
   
        static constexpr int numberOfEconomics = 8;     //number economics houses    
        static constexpr int numberOfStandards = 10;    //number of standard houses
        static constexpr int numberOfLuxury = 6;        //number of luxury houses

};

#endif //GAMEFIELD_H