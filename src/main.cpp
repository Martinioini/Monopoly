#include <iostream>
#include "Map.cpp"
#include <string>
#include <algorithm>
#include <queue>


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
    std::queue<Player> Players;
    if (start(map))
    {
        Player Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};
        path[0].addPlayer(Giocatore1.getIndex());
        path[0].addPlayer(Giocatore2.getIndex());
        path[0].addPlayer(Giocatore3.getIndex());
        path[0].addPlayer(Giocatore4.getIndex());
    }
    else
    {
        PlayerNPC Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};
    }
}