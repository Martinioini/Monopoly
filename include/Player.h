#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Cell.h"
#include <vector>

class Player
{
    

    public:

        virtual void addProperty(std::string s) = 0;

        virtual void printProperty() = 0;
        
        virtual void setPosition(int position) = 0;

        virtual int getBalance() = 0;

        virtual int getPosition() = 0;

        virtual int getIndex() = 0;

        virtual bool payTo(int credit, Player* p) = 0;

        virtual int throwDice() = 0;

        virtual bool hasBalance(int price) = 0;     

        virtual void addMoney(int money) = 0;

        virtual bool buyCell(int price, Cell cell) = 0;

        virtual bool buyHouse(Cell cell) = 0;
        
        virtual bool getNextMove() = 0;

};



#endif //PLAYER_H