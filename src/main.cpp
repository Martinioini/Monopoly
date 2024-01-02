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
    Player PlayersArr[4];
    
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

        PlayersArr[0] = Giocatore1;
        PlayersArr[1] = Giocatore2;
        PlayersArr[2] = Giocatore3;
        PlayersArr[3] = Giocatore4;

        field.setPlayerCell(0, Giocatore1.getIndex());    //inizializza il gioco, inserendo i player nella casella P
        field.setPlayerCell(0, Giocatore2.getIndex());
        field.setPlayerCell(0, Giocatore3.getIndex());
        field.setPlayerCell(0, Giocatore4.getIndex()); 

        int first = Giocatore1.throwDice();   // otteniamo i 4 tiri per capire l'ordine dei giocatori
        int second = Giocatore1.throwDice();
        int third = Giocatore1.throwDice();
        int four = Giocatore1.throwDice();

        pairList.push(std::make_pair(Giocatore1.throwDice(), Giocatore1)); // creiamo le coppie giocatori-numero dei dadi per capire l'ordine dei giocatori
        pairList.push(std::make_pair(Giocatore2.throwDice(), Giocatore2));
        pairList.push(std::make_pair(Giocatore3.throwDice(), Giocatore3));
        pairList.push(std::make_pair(Giocatore4.throwDice(), Giocatore4));

        while(players.size() < 4)
        {
            std::pair<int, Player> temp = pairList.top();   //creaimo la coda che deciderà il turno dei giocatori per tutta la partita
            pairList.pop();
            players.push(temp.second);
        }
    }

    else
    {
        PlayerNPC Giocatore1{1};
        PlayerNPC Giocatore2{2};
        PlayerNPC Giocatore3{3};
        PlayerNPC Giocatore4{4};

        PlayersArr[0] = Giocatore1;
        PlayersArr[1] = Giocatore2;
        PlayersArr[2] = Giocatore3;
        PlayersArr[3] = Giocatore4;

        field.setPlayerCell(0, Giocatore1.getIndex());
        field.setPlayerCell(0, Giocatore2.getIndex());
        field.setPlayerCell(0, Giocatore3.getIndex());
        field.setPlayerCell(0, Giocatore4.getIndex());

        int first = Giocatore1.throwDice();   // otteniamo i 4 tiri per capire l'ordine dei giocatori
        int second = Giocatore1.throwDice();
        int third = Giocatore1.throwDice();
        int four = Giocatore1.throwDice();

        pairList.push(std::make_pair(Giocatore1.throwDice(), Giocatore1)); // creiamo le coppie giocatori-numero dei dadi per capire l'ordine dei giocatori
        pairList.push(std::make_pair(Giocatore2.throwDice(), Giocatore2));
        pairList.push(std::make_pair(Giocatore3.throwDice(), Giocatore3));
        pairList.push(std::make_pair(Giocatore4.throwDice(), Giocatore4));

        while(players.size() < 4)
        {
            std::pair<int, Player> temp = pairList.top();   //creaimo la coda che deciderà il turno dei giocatori per tutta la partita
            pairList.pop();
            players.push(temp.second);
        }
    }
    field.printMap();
    while (players.size() > 1)
    {
        bool hasMoney = true;
        Player currentPlayer = players.front();
        players.pop();
        int diceNumber = currentPlayer.throwDice();
        int newPosition = diceNumber + currentPlayer.getPosition();
        
        if (newPosition >= 28)
        {
            currentPlayer.addMoney(20);
            newPosition = newPosition % 28;
        }

        field.removePlayer(currentPlayer.getPosition(), currentPlayer.getIndex());
        currentPlayer.setPosition(newPosition);
        field.setPlayerCell(currentPlayer.getPosition(), currentPlayer.getIndex());
        Cell currentCell = field.getCell(currentPlayer.getIndex());

        if (!currentCell.isPurchased())
        {   
            bool choice = currentPlayer.getNextMove();

            if(currentCell.getCategory() == "E" && choice)
            {
                currentPlayer.buyCell(6, currentCell);
            }
            else if(currentCell.getCategory() == "S" && choice)
            {
                currentPlayer.buyCell(10, currentCell);
            }
            else if(currentCell.getCategory() == "L" && choice)
            {
                currentPlayer.buyCell(20, currentCell);
            }
        }

        else
        {
            if (currentCell.getOwnerIndex() == currentPlayer.getIndex())
            {
                if(currentCell.getHouseLevel() != 3)
                {
                    bool choice = currentPlayer.getNextMove();
                    if (choice) {
                        currentPlayer.buyHouse(currentCell);
                        currentCell.increaseHouseLevel();
                        currentPlayer.addProperty(currentCell.getCategory());
                    }
                }
            }

            else
            {
                if (currentCell.getHouseLevel() == 2)
                {
                    if (currentCell.getCategory() == "E")
                    {
                        if (currentPlayer.hasBalance(2))
                        {
                            currentPlayer.payTo(2, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell.getCategory() == "S")
                    {
                        if (currentPlayer.hasBalance(4))
                        {
                            currentPlayer.payTo(4, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell.getCategory() == "L")
                    {
                        if (currentPlayer.hasBalance(7))
                        {
                            currentPlayer.payTo(7, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                }

                else
                {
                    if (currentCell.getCategory() == "E")
                    {
                        if (currentPlayer.hasBalance(4))
                        {
                            currentPlayer.payTo(4, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell.getCategory() == "S")
                    {
                        if (currentPlayer.hasBalance(8))
                        {
                            currentPlayer.payTo(8, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell.getCategory() == "L")
                    {
                        if (currentPlayer.hasBalance(14))
                        {
                            currentPlayer.payTo(14, PlayersArr[currentCell.getOwnerIndex() - 1]);
                        
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                }
            }
        }
        if (hasMoney)
        {
            players.push(currentPlayer);
        }
        else
        {
            int indexLoser = currentPlayer.getIndex();
            field.removePlayerProperties(indexLoser);
            field.removePlayer(currentPlayer.getPosition(), indexLoser); //viene rimosso lo zesty loser
        }
    }
}