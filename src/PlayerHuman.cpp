#include "PlayerHuman.h"
#include <random>

PlayerHuman::PlayerHuman()
{
    _balance = 100;
}

PlayerHuman::PlayerHuman(int index)
{
    _index = index;
    _position = 0;
    _balance = 100;
}


void PlayerHuman::printProperty(GameField field)
{
    std::cout << "Giocatore " << _index << ": ";
    for (int i = 0; i < 28; i++)
    {
        Cell* currentCell = field.getCell(i);
        if (currentCell->getOwnerIndex() == _index)
        {
            std::cout << currentCell->getPosition() << std::endl;
        }
    }
}

void PlayerHuman::setPosition(int position)
{
    _position = position;
}

int PlayerHuman::getPosition()
{
    return _position;
}

int PlayerHuman::getBalance()
{
    return _balance;
}

int PlayerHuman::getIndex()
{
    return _index;
}

bool PlayerHuman::payTo(int credit, Player* p)
{
    if(hasBalance(credit))
    {
        _balance -= credit;
        p->addMoney(credit);
        return true;
    }
    p->addMoney(_balance);
    _balance = 0;
    return false;
}

void PlayerHuman::addMoney(int money)
{
    _balance += money;
}

int PlayerHuman::throwDice()
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

bool PlayerHuman::hasBalance(int price)
{
    return price < _balance;
}

bool PlayerHuman::buyCell(int price, Cell* cell) 
{
    if(hasBalance(price))
    {
        _balance -= price;
        cell->setOwner(_index);
        cell->increaseHouseLevel();
        return true;
    }
    return false;
}

bool PlayerHuman::buyHouse(Cell* cell)
{
    if(cell->getHouseLevel() < 2)
    {
        if(cell->getCategory() == "E")
        {
            if(hasBalance(3))
            {
                _balance -= 3;
                cell->increaseHouseLevel();
                return true;
            }
        }
        else if(cell->getCategory() == "S")
        {
            if(hasBalance(5))
            {
                _balance -= 5;
                cell->increaseHouseLevel();
                return true;
            }
        }
        else if(cell->getCategory() == "L"){
            if(hasBalance(10))
            {
                _balance -= 10;
                cell->increaseHouseLevel();
                return true;
            }
        }
    }
    return false;
}

bool PlayerHuman::getNextMove()
{
    std::string response = "";
    std::cout << "Vuoi comprare o migliorare la proprieta'?" << std::endl;
    do {
        std::cin >> response;
        if(response != "si" && response != "no")
        {
            std::cout << "Input invalido, rispondi con si o no" << std::endl;
        }
    } while (response != "si" && response != "no");
    return response == "si";
}