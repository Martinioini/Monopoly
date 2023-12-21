#ifndef MAP_H
#define MAP_H

#include <string>
#include "Cell.h"

class Map
{
    private:

        static constexpr int mapLength = 28;

        Cell path[mapLength];    //mappa

    public:
    
        static constexpr int numberOfCorners = 4;   
        static constexpr int numberOfCheaps = 8;        //number cheap houses    
        static constexpr int numberOfNormals = 10;      //number of normal houses
        static constexpr int numberOfLuxury = 6;        //number of luxury houses

        Map();

        void generatePath();     //generate the random number of cells in the path following constraints

        void printMap();

};



#endif //MAP