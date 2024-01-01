#include <iostream>
#include "GameField.h"
#include <string>
#include <algorithm>
#include <queue>
#include "PlayerNPC.h"
#include <utility>


bool start(GameField field)
{
    field.printMap();
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
    GameField field;
    std::queue<Player> players;
    
    auto compare = [](const std::pair<int, Player>& a, const std::pair<int, Player>& b) 
    {
        return a.first < b.first;
    };
    std::priority_queue<std::pair<int, Player>, std::vector<std::pair<int, Player>>, decltype(compare)> pairList(compare);

    if (start(field))
    {
        Player Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};

        field.setPlayerCell(0, Giocatore1.getIndex());
        field.setPlayerCell(0, Giocatore2.getIndex());
        field.setPlayerCell(0, Giocatore3.getIndex());
        field.setPlayerCell(0, Giocatore4.getIndex()); 

        int first = Giocatore1.throwDice();
        int second = Giocatore1.throwDice();
        int third = Giocatore1.throwDice();
        int four = Giocatore1.throwDice();

        std::cout << first << second << third << four << "\n";

        pairList.push(std::make_pair(Giocatore1.throwDice(), Giocatore1));
        pairList.push(std::make_pair(Giocatore2.throwDice(), Giocatore2));
        pairList.push(std::make_pair(Giocatore3.throwDice(), Giocatore3));
        pairList.push(std::make_pair(Giocatore4.throwDice(), Giocatore4));

        while(players.size() < 4)
        {
            std::pair<int, Player> temp = pairList.top();
            pairList.pop();
            std::cout << temp.second.getIndex();
            players.push(temp.second);
        }
    }

    else
    {
        PlayerNPC Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};
        field.setPlayerCell(0, Giocatore1.getIndex());
        field.setPlayerCell(0, Giocatore2.getIndex());
        field.setPlayerCell(0, Giocatore3.getIndex());
        field.setPlayerCell(0, Giocatore4.getIndex());
    }
    field.printMap();
}