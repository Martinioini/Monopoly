#include "Map.h"
#include <iostream>
#include <string>

/// @brief 
Map::Map()
{
    generatePath();
}

void Map::generatePath()
{
}

void Map::printMap()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)    
        {
            switch(i)
            {
                case 0:
                    std::cout << path[j] << "\t"; 
                    break;
                case 1:
                    if(j == 0)
                        std::cout << path[27] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[8] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 2:
                    if(j == 0)
                        std::cout << path[26] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[9] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 3:
                    if(j == 0)
                        std::cout << path[25] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[10] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 4:
                    if(j == 0)
                        std::cout << path[24] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[11] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 5:
                    if(j == 0)
                        std::cout << path[23] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[12] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 6:
                    if(j == 0)
                        std::cout << path[22] << "\t";
                    else 
                        if(j == 7)
                            std::cout << path[13] << "\t";
                        else
                            std::cout << "\t";
                    break; 
                case 7:
                    std::cout << path[28-(7+j)] << "\t";

            }
        }
    }
}



