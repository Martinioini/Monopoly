#include <iostream>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

virtual class Player
{
    private:

        int _index;

        int _balance = 100;

    public:

        Player(int index);
        
        int getBalance();

        int getIndex();

        void payTo(int credit, Player p);

        int throwDice();

        bool hasBalance(int price);     

        void addMoney(int money);

        virtual bool buyCell(int price, Cell cell);

        virtual bool buyHouse(Cell cell);
};



#endif //PLAYER_H