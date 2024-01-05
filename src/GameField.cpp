#include "GameField.h"
#include <iostream>
#include <string>
#include <cstdlib>

/// @brief 
GameField::GameField()
{
    generatePath();
}

void GameField::setCell()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)    
        {
            switch(i)
            {
                case 0:
                    path[j].setPosition("A" + std::to_string(j+1));
                    break;
                case 1:
                    if(j == 0)
                        path[27].setPosition("B1");
                    else 
                        if(j == 7)
                            path[8].setPosition("B8");
                    break; 
                case 2:
                    if(j == 0)
                        path[26].setPosition("C1");
                    else 
                        if(j == 7)
                            path[9].setPosition("C8");
                    break; 
                case 3:
                    if(j == 0)
                        path[25].setPosition("D1");
                    else 
                        if(j == 7)
                            path[10].setPosition("D8");
                    break; 
                case 4:
                    if(j == 0)
                        path[24].setPosition("E1");
                    else 
                        if(j == 7)
                            path[11].setPosition("E8");
                    break; 
                case 5:
                    if(j == 0)
                        path[23].setPosition("F1");
                    else 
                        if(j == 7)
                            path[12].setPosition("F8");
                    break; 
                case 6:
                    if(j == 0)
                        path[22].setPosition("G1");
                    else 
                        if(j == 7)
                            path[13].setPosition("G8");
                    break; 
                case 7:
                    path[28-(7+j)].setPosition("A" + std::to_string(j+1));
                    break;
            }
        }
    }
}

void GameField::generatePath()
{
    srand (((unsigned) time(NULL)));
    int e = 0;
    int s = 0;
    int l = 0;
    int random = 0;
    setCell();
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

void GameField::printMap()
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

void GameField::setPlayerCell(int position, int playerIndex)
{
    path[position].addPlayer(playerIndex);
}

void GameField::removePlayer(int position, int playerIndex)
{
    path[position].removePlayer(playerIndex);
}

Cell* GameField::getCell(int index)
{
    return path + index;
}

void GameField::removePlayerProperties(int playerIndex)
{
    for (int i = 0; i < 28; i++)
    {
        if (path[i].getOwnerIndex() == playerIndex)
        {
            path[i].deleteOwner();
        }
    }
}