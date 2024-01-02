#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Cell.h"
#include <vector>

class Player
{
    protected:

        int property_number = 0;
        std::string property[24];
        int _index;
        int _position;
        int _balance = 100;
        std::string position = "";

    public:

        Player();

        Player(int index);

        void addProperty(std::string s);

        void printProperty();
        
        void setPosition(int position);

        int getBalance();

        int getPosition();

        int getIndex() const;

        bool payTo(int credit, Player p);

        int throwDice();

        bool hasBalance(int price);     

        void addMoney(int money);

        virtual bool buyCell(int price, Cell cell);

        virtual bool buyHouse(Cell cell);
        
        virtual bool getNextMove();

};



#endif //PLAYER_H