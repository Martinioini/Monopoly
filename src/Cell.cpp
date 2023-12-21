#include "../include/Cell.h"

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