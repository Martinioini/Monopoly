#include <iostream>
#include <string>

#ifndef CELL_H
#define CELL_H

class Cell
{
    private:
        
        bool purchased;          //stato di vendita
        std::string category;    //categoria C, S, L, P, void
        int house_level;         //livello immobile 0(nessuna casa), 1(casa normale), 2(albergo)
        int owner;               //player propetario, se > 4 allora non acquisita
        std::string position;
        int player_index[4];
        int numberOfPlayers;

    public:

        Cell();
        
        bool isPurchased();

        int getOwnerIndex();

        int getHouseLevel();

        std::string getPosition();

        std::string getCategory();

        void increaseHouseLevel();

        void deleteOwner();

        void setPurchase();

        void setOwner(int index);
        
        void setCategory(int c);

        std::string toStringHouse();

        void addPlayer(Player p);
        
        void removePlayer(Player p);
        
        int getPlayer(int index);

        int getNumberOfPlayers();

        friend std::ostream& operator<<(std::ostream& os, Cell& cell);

};

#endif //CELL_H
