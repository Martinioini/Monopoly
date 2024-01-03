#ifndef PLAYERNPC_H
#define PLAYERNPC_H

#include "Player.h"
#include <iostream>
#include <string>


class PlayerNPC : public Player
{
    private:

        int property_number = 0;
        std::string property[24];
        int _index;
        int _position;
        int _balance = 100;
        std::string position = "";
    
    public:

        PlayerNPC(int index);

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

        virtual bool buyCell(int price, Cell cell);

        virtual bool buyHouse(Cell cell);
        
        virtual bool getNextMove();
  
};



#endif //PLAYERNPC_H