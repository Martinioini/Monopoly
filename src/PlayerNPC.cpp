#include "PlayerNPC.h"
#include <random>

PlayerNPC::PlayerNPC(int index)
{
    _index = index;
    _position = 0;
}

void PlayerNPC::addProperty(std::string s)
{
    property[property_number++] = s;
}

void PlayerNPC::printProperty()
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

void PlayerNPC::setPosition(int position)
{
    _position = position;
}

int PlayerNPC::getPosition()
{
    return _position;
}

int PlayerNPC::getBalance()
{
    return _balance;
}

int PlayerNPC::getIndex()
{
    return _index;
}

bool PlayerNPC::payTo(int credit, Player* p)
{
    if(hasBalance(credit))
    {
        _balance -= credit;
        p->addMoney(credit);
        return true;
    }
    p->addMoney(_balance);
    return false;
}

void PlayerNPC::addMoney(int money)
{
    _balance += money;
}

int PlayerNPC::throwDice()
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

bool PlayerNPC::hasBalance(int price)
{
    return price < _balance;
}

bool PlayerNPC::buyCell(int price, Cell cell)    //returna true se andato a buon fine e false altrimenti
{
    srand (((unsigned) time(NULL)));
    int random = 1 + (rand() % 4);
    
    if(random == 1)
    {
        if(hasBalance(price))
        {
            _balance -= price;
            cell.setOwner(_index);
            cell.setPurchase();
            return true;
        }
    }

    return false;
}

bool PlayerNPC::buyHouse(Cell cell)
{
    srand (((unsigned) time(NULL)));
    int random = 1 + (rand() % 4);
    
    if(random == 1)
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

        else if(cell.getCategory() == "L")
        {
            if(hasBalance(10))
            {
                _balance -= 10;
                cell.increaseHouseLevel();
                return true;
            }
        }
    }
    return false;
}

bool PlayerNPC::getNextMove()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 4);
    int possibility = dist(gen);
    return possibility == 1;
}
