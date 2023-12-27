#include "Map.h"
#include <iostream>
#include <string>
#include <cstdlib>

/// @brief 
Map::Map()
{
    generatePath();
}

void Map::generatePath()
{
    srand (((unsigned) time(NULL)));
    int e = 0;
    int s = 0;
    int l = 0;
    int random = 0;

    for(int i = 0 ; i < 28 ; i++)
    {
        if(i == 0)
        {
            path[i].setCategory(4);    //starting cell
        }
            
        else if(i == 7 || i == 14 || i == 21)           
        {
            path[i].setCategory(0);    //angular cell
        }

        else
        {
            bool done = false;

            while(!done)
            {
                random = 1 + (rand() % 3);

                if(random == 1 && e < numberOfEconomics)
                {
                    path[i].setCategory(1);
                    done = true;
                    e++;
                }

                else if(random == 2 && s < numberOfStandards)
                {
                    path[i].setCategory(2);
                    done = true;
                    s++;
                }

                else if(random == 3 && e < numberOfLuxury)
                {
                    path[i].setCategory(3);
                    done = true;
                    l++;
                }
             }
        }      
    }
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
        std::cout << "\n";
    }
}



