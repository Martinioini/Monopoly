#include "Player.h"

Player::Player(int index)
{
    _index = index;
}

void Player::addProperty(std::string s)
{
    property[property_number++] = s;
}

void printProperty()
{
    std::cout << "Giocatore " << _index << ": ";
    for (int i = 0; i < property_number; i++)
    {
        if (i == (property_number - 1))
        {
            std::cout << property[i] << std::endl;
        }
        else
        {
            std::cout << property[i] << ", ";
        }
    }
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


