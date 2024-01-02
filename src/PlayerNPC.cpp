#include "PlayerNPC.h"
#include <random>

PlayerNPC::PlayerNPC(int index) : Player(index)
{}

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
