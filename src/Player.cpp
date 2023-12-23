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

void Player::pay(int price)
{
    _balance -= price;
}

void Player::getCredit(int credit, Player p)
{
    _balance -= credit
}

