#include "Cell.h"

Cell::Cell()
{
    house_level = 0;
    purchased = false;
    owner = 0;
    player_index[0] = 1;
    numberOfPlayers = 1;
}


bool Cell::isPurchased()
{
    return purchased;
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
    purchased = false;
}

void Cell::setPurchase()
{
    purchased = true;
}

void Cell::setOwner(int index)
{
    owner = index;
    purchased = true;
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
    if( house_level == 0)
        return " ";
    else
        if (house_level == 1)
            return "*";
    return "^";
}

void Cell::addPlayer(Player p) 
{
    if(player_index[0] == 0)
    {
        player_index[0] = p.getIndex();
    }
        
    else if (player_index[1] == 0)
    {
        player_index[1] = p.getIndex();
    }
        
    else if (player_index[2] == 0)
    {
        player_index[2] = p.getIndex();
    }
        
    else
    {
        player_index[3] = p.getIndex();
    }
        
}

void Cell::removePlayer(Player p)
{
    int i = 0;
    do
    {
        if(player_index[i] == p.getIndex())
        {
            player_index[i] = 0;
        }
            
    } while(player_index[i - 1] != p.getIndex());
}

int Cell::getPlayer(int index)
{
    return player_index[index];
}

int Cell::getNumberOfPlayers()
{
    return  numberOfPlayers;
}

std::ostream& operator<<(std::ostream& os, Cell& cell) 
{
    if(cell.getNumberOfPlayers() == 0)
    {
        os << "|" << cell.getCategory() << cell.toStringHouse() << "|";
        return os;
    }
    else if(cell.getNumberOfPlayers() == 1)
    {
        os << "|" << cell.getCategory() << cell.toStringHouse() << cell.getPlayer(0) << "|";
        return os;
    }
    else
    {
        os << "|" << cell.getCategory() << cell.toStringHouse() ;
        for(int i = 0; i < cell.getNumberOfPlayers(); i++)
        {
            os << " " << cell.getPlayer(i);
        }
        os << "|";
        return os;
    }


}

