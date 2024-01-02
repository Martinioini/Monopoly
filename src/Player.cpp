#include "Player.h"
#include <random>

Player::Player()
{
}

Player::Player(int index)
{
    _index = index;
    _position = 0;
}

void Player::addProperty(std::string s)
{
    property[property_number++] = s;
}

void Player::printProperty()
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

void Player::setPosition(int position)
{
    _position = position;
}

int Player::getPosition()
{
    return _position;
}

int Player::getBalance()
{
    return _balance;
}

int Player::getIndex() const
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
    // Inizializza un generatore di numeri casuali
    std::random_device rd;
    std::mt19937 gen(rd());

    // Genera due numeri casuali da 1 a 6
    std::uniform_int_distribution<int> dist(1, 6);
    int dice1 = dist(gen);
    int dice2 = dist(gen);

    // Restituisce la somma dei due numeri
    return dice1 + dice2;
}

bool Player::hasBalance(int price)
{
    return price < _balance;
}

bool Player::buyCell(int price, Cell cell) 
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

bool Player::buyHouse(Cell cell)
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

bool Player::getNextMove()
{
    std::string response = "";
    do {
        std::cin >> response;
        if(response != "si" && response != "no")
        {
            std::cout << "Input invalido, rispondi con si o no" << std::endl;
        }
    } while (response != "si" && response != "no");
    return response == "si";
}