#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(int c, int s, int l)
{
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
    owner = 5;
    purchased = false;
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
        category = " ";
        break;
    case 1:
        category = "E";
        break;
    case 2:
        category = "S";
        break;
    case 3:
        category = "L";
        break;
    case 4:
        category = "P";
        break;
    }
    category = c;
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

int Cell::getPlayer()
{
    return player;
}

std::ostream& operator<<(std::ostream& os, Cell& cell) {
    os << "|" << cell.getCategory() << cell.toStringHouse() << cell.getPlayer() << "|";
    return os;
}
