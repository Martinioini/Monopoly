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
        int _balance;
        std::string position = "";

    public:

        PlayerHuman();

        PlayerHuman(int index);

        void addProperty(std::string s) override;

        void printProperty() override;
        
        void setPosition(int position) override;

        int getBalance() override;

        int getPosition() override;

        int getIndex() override;

        bool payTo(int credit, Player* p) override;

        int throwDice() override;

        bool hasBalance(int price) override;     

        void addMoney(int money) override;

        bool buyCell(int price, Cell* cell) override;

        bool buyHouse(Cell* cell) override;
        
        bool getNextMove() override;

};



#endif //PLAYERHUMAN_H