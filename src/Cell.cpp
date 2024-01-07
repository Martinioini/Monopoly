#include "Cell.h"

Cell::Cell()
{
    house_level = -1;
    owner = 0;
}

void Cell::setPosition(std::string s)
{
    position = s;
}

int Cell::getOwnerIndex()
{
    return owner;
}

int Cell::getHouseLevel()
{
    return house_level;
}

std::string Cell::getPosition()
{
    return position;
}

std::string Cell::getCategory()
{
    return category;
}

void Cell::increaseHouseLevel()
{
    house_level++;
}

void Cell::deleteOwner()
{
    owner = 0;
    house_level = -1;
}

void Cell::setOwner(int index)
{
    owner = index;
}

void Cell::setCategory(int c)
{
    switch (c)
    {
    case 0:
        category = " ";    //empty
        break;
    case 1:
        category = "E";    //cheap
        break;
    case 2:
        category = "S";    //standard
        break;
    case 3:
        category = "L";    //luxury
        break;
    case 4:
        category = "P";    //start
        break;
    }
}

std::string Cell::toStringHouse()
{
    if(house_level == 1)
    {
        return "*";
    }
    else
    {
        if (house_level == 2){
            return "^";
        }
    }
    return " ";
}

void Cell::addPlayer(int player) 
{
    players.push_back(player);
        
}

void Cell::removePlayer(int player)
{
    players.remove(player);
}

std::ostream& operator<<(std::ostream& os, Cell& cell) 
{
    if(cell.players.size() == 0)
    {
        os << "|" << cell.getCategory() << cell.toStringHouse() << "|";
        return os;
    }

    else
    {
        os << "|" << cell.getCategory() << cell.toStringHouse();
        for(int x : cell.players)
        {
            os << x;    
        }
        os << "|";
        return os;     
    }
}

