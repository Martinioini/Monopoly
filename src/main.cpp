#include <iostream>
#include "Map.h"
#include <string>
#include <algorithm>
#include <queue>
#include "PlayerNPC.h"


bool start(Map map)
{
    map.printMap();
    std::cout << "Benvenuto nel gioco del Monopoly realizzato da: Edin Milenko, Alessandro Martini, Mattia Ballarin" << std::endl;
    std::cout << "Vuoi giocare o no? Rispondi con si o no: ";
    std::string s = "";
    std::string a = "";
    do {
        std::cin >> s;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s != "si" && s != "no")
        {
            std::cout << "Input invalido, rispondi con si o no" << std::endl;
        }
    } while (s != "si" && s != "no");
    return s == "si";
}

int main()
{
    Map map;
    std::queue<Player> players;
    if (start(map))
    {
        Player Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};
        map.setPlayerCell(0, Giocatore1.getIndex());
        map.setPlayerCell(0, Giocatore2.getIndex());
        map.setPlayerCell(0, Giocatore3.getIndex());
        map.setPlayerCell(0, Giocatore4.getIndex());
    }

    else
    {
        PlayerNPC Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};
        map.setPlayerCell(0, Giocatore1.getIndex());
        map.setPlayerCell(0, Giocatore2.getIndex());
        map.setPlayerCell(0, Giocatore3.getIndex());
        map.setPlayerCell(0, Giocatore4.getIndex());
    }
}