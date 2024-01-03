#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "Player.h"
#include <iostream>
#include <string>
#include "Cell.h"
#include <vector>

class PlayerHuman : public Player
{
    private:

        int property_number = 0;
        std::string property[24];
        int _index;
        int _position;
        int _balance = 100;
        std::string position = "";

    public:

        PlayerHuman();

        PlayerHuman(int index);

        void addProperty(std::string s);

        void printProperty();
        
        void setPosition(int position);

        int getBalance();

        int getPosition();

        int getIndex();

        bool payTo(int credit, Player* p);

        int throwDice();

        bool hasBalance(int price);     

        void addMoney(int money);

        bool buyCell(int price, Cell cell);

        bool buyHouse(Cell cell);
        
        bool getNextMove();

};



#endif //PLAYERHUMAN_H