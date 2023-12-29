#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Cell.h"

class Player
{
    protected:

        int property_number = 0;
        std::string property[24];
        int _index;
        int _balance = 100;
        std::string position = "";

    public:

        Player(int index);

        void addProperty(std::string s);

        void printProperty();
        
        int getBalance();

        int getIndex() const;

        bool payTo(int credit, Player p);

        int throwDice();

        bool hasBalance(int price);     

        void addMoney(int money);

        virtual bool buyCell(int price, Cell cell);

        virtual bool buyHouse(Cell cell);

};



#endif //PLAYER_H