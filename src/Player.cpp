#include "Player.h"
#include <iostream>
#include <string>

Player::Player(int index)
{
    _index = index;
}

int Player::getBalance()
{
    return _balance;
}

int Player::getIndex()
{
    return _index;
}

bool Player::payTo(int credit, Player p)
{
    if(hasBalance(credit))
    {
        _balance -= credit;
        p.addMoney(credit);
        return true;
    }
    p.addMoney(_balance);
    return false;
}

void Player::addMoney(int money)
{
    _balance += money;
}

int Player::throwDice()
{
    srand (((unsigned) time(NULL)));
    return ((1 + (rand() % 6)) + (1 + (rand() % 6)));
}

bool Player::hasBalance(int price)
{
    return price < _balance;
}

virtual bool Player::buyCell(int price, Cell cell)
{
    if(hasBalance(price))
    {
        _balance -= price;
        cell.setOwner(_index);
        cell.setPurchase();
        return true;
    }
    return false;
}

virtual bool Player::buyHouse(Cell cell)
{
    if(cell.getCategory() == "E")
    {
        if(hasBalance(3))
        {
            _balance -= 3;
            cell.increaseHouseLevel();
            return true;
        }
    }
    else if(cell.getCategory() == "S")
    {
        if(hasBalance(5))
        {
            _balance -= 5;
            cell.increaseHouseLevel();
            return true;
        }
    }
    else if(cell.getCategory() == "L"){
        if(hasBalance(10))
        {
            _balance -= 10;
            cell.increaseHouseLevel();
            return true;
        }
    }
    return false;
}


