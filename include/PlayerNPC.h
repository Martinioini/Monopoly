#ifndef PLAYERNPC_H
#define PLAYERNPC_H

#include "Player.h"
#include <iostream>
#include <string>


class PlayerNPC : public Player
{
    private:

        int _index;
        int _position;
        int _balance;
        std::string position = "";
    
    public:

        PlayerNPC();

        PlayerNPC(int index);

        void printProperty(GameField field) override;
        
        void setPosition(int position) override;

        int getBalance() override;

        int getPosition() override;

        int getIndex() override;

        bool payTo(int credit, Player* p) override;

        int throwDice() override;

        bool hasBalance(int price) override;     

        void addMoney(int money) override;

        virtual bool buyCell(int price, Cell* cell) override;

        virtual bool buyHouse(Cell* cell) override;
        
        virtual bool getNextMove() override;
  
};



#endif //PLAYERNPC_H