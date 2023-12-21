#ifndef CELL_H
#define CELL_H

#include <string>

class Cell
{
    private:
        
        bool purchased;          //stato di vendita
        std::string category;    //categoria C, S, L, P, void
        int house_level;         //livello immobile 0(nessuna casa), 1(casa normale), 2(albergo)
        int owner;               //player propetario, se > 4 allora non acquisita
        std::string position;

    public:

        Cell(int c, int s, int l);
        
        bool isPurchased();

        int getOwnerIndex();

        int getHouseLevel();

        std::string getPosition();

        void increaseHouseLevel();

        void deleteOwner();

        void setOwner(int index);

};

#endif //CELL
