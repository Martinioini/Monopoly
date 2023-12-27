#ifndef MAP_H
#define MAP_H

#include "Cell.h"
#include <iostream>
#include <string>

class Map
{
    private:

        static constexpr int mapLength = 28;

        Cell path[mapLength];    //mappa

    public:
    
        Map();  

        void generatePath();     //generate the random number of cells in the path following constraints

        void printMap();
   
        static constexpr int numberOfEconomics = 8;     //number economics houses    
        static constexpr int numberOfStandards = 10;    //number of standard houses
        static constexpr int numberOfLuxury = 6;        //number of luxury houses

};

#endif //MAP_H