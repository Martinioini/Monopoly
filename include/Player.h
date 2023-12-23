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

        void pay(int price);

        void getCredit(int credit, Player p);

        int throwDice();

        virtual void buyHouse();
};



#endif //PLAYER_H