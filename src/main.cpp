#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <typeinfo>
#include "GameField.h"
#include "Player.h"
#include "PlayerHuman.h"
#include "PlayerNPC.h"



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

void showRanking(Player* PlayersArr[], int size)
{
    int arr_index[size];
    int arr_balance[size];

    for (int i = 0; i < size; i++)
    {
        arr_index[i] = PlayersArr[i]->getIndex();
        arr_balance[i] = PlayersArr[i]->getBalance();
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr_balance[i] < arr_balance[j])
            {
                std::swap(arr_index[i], arr_index[j]);
                std::swap(arr_balance[i], arr_balance[j]);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "* - Giocatore " << arr_index[i] << " con un bilancio di " << arr_balance[i] << ";" << std::endl;
    }
}

int main()
{
    GameField* field = new GameField();
    std::queue<Player*> players;
    Player* PlayersArr[4];
    int j = 0;
    
    auto compare = [](const std::pair<int, Player*>& a, const std::pair<int, Player*>& b) 
    {
        return a.first < b.first;
    };
    std::priority_queue<std::pair<int, Player*>, std::vector<std::pair<int, Player*>>, decltype(compare)> pairList(compare);
    bool isHuman = start(*field);

    if (isHuman)
    {
        PlayerHuman* Giocatore1 = new PlayerHuman(1);
        PlayerNPC* Giocatore2 = new PlayerNPC(2);
        PlayerNPC* Giocatore3 = new PlayerNPC(3);
        PlayerNPC* Giocatore4 = new PlayerNPC(4);

        PlayersArr[0] = Giocatore1;
        PlayersArr[1] = Giocatore2;
        PlayersArr[2] = Giocatore3;
        PlayersArr[3] = Giocatore4;

        field->setPlayerCell(0, Giocatore1->getIndex());    //inizializza il gioco, inserendo i player nella casella P
        field->setPlayerCell(0, Giocatore2->getIndex());
        field->setPlayerCell(0, Giocatore3->getIndex());
        field->setPlayerCell(0, Giocatore4->getIndex()); 

        int first = Giocatore1->throwDice();   // otteniamo i 4 tiri per capire l'ordine dei giocatori
        int second = Giocatore1->throwDice();
        int third = Giocatore1->throwDice();
        int four = Giocatore1->throwDice();

        pairList.push(std::make_pair(Giocatore1->throwDice(), Giocatore1)); // creiamo le coppie giocatori-numero dei dadi per capire l'ordine dei giocatori
        pairList.push(std::make_pair(Giocatore2->throwDice(), Giocatore2));
        pairList.push(std::make_pair(Giocatore3->throwDice(), Giocatore3));
        pairList.push(std::make_pair(Giocatore4->throwDice(), Giocatore4));

        while(players.size() < 4)
        {
            std::pair<int, Player*> temp = pairList.top();   //creaimo la coda che deciderà il turno dei giocatori per tutta la partita
            pairList.pop();
            players.push(temp.second);
        }
    }

    else
    {
        PlayerNPC* Giocatore1 = new PlayerNPC(1);
        PlayerNPC* Giocatore2 = new PlayerNPC(2);
        PlayerNPC* Giocatore3 = new PlayerNPC(3);
        PlayerNPC* Giocatore4 = new PlayerNPC(4);

        PlayersArr[0] = Giocatore1;
        PlayersArr[1] = Giocatore2;
        PlayersArr[2] = Giocatore3;
        PlayersArr[3] = Giocatore4;

        field->setPlayerCell(0, Giocatore1->getIndex()); 
        field->setPlayerCell(0, Giocatore2->getIndex());
        field->setPlayerCell(0, Giocatore3->getIndex());
        field->setPlayerCell(0, Giocatore4->getIndex());

        int first = Giocatore1->throwDice();   // otteniamo i 4 tiri per capire l'ordine dei giocatori
        int second = Giocatore1->throwDice();
        int third = Giocatore1->throwDice();
        int four = Giocatore1->throwDice();

        pairList.push(std::make_pair(Giocatore1->throwDice(), Giocatore1)); // creiamo le coppie giocatori-numero dei dadi per capire l'ordine dei giocatori
        pairList.push(std::make_pair(Giocatore2->throwDice(), Giocatore2));
        pairList.push(std::make_pair(Giocatore3->throwDice(), Giocatore3));
        pairList.push(std::make_pair(Giocatore4->throwDice(), Giocatore4));

        while(players.size() < 4)
        {
            std::pair<int, Player*> temp = pairList.top();   //creaimo la coda che deciderà il turno dei giocatori per tutta la partita
            pairList.pop();
            players.push(temp.second);
        }
    }

    field->printMap();
    //sleep(2);
    system("clear"); // sul serio?
    int turn_count = 0;

    while (players.size() > 1 && turn_count < 500)
    {
        bool hasMoney = true;
        Player* playerPtr = players.front();
        
        int diceNumber = playerPtr->throwDice();
        std::cout << "Il giocatore " << playerPtr->getIndex() << " ha ottenuto " << diceNumber << " dal lancio dei dadi" << std::endl;
        int newPosition = diceNumber + playerPtr->getPosition();
        
        if (newPosition >= 28)
        {
            playerPtr->addMoney(20);
            newPosition = newPosition % 28;
        }

        field->removePlayer(playerPtr->getPosition(), playerPtr->getIndex());
        playerPtr->setPosition(newPosition);
        field->setPlayerCell(playerPtr->getPosition(), playerPtr->getIndex());
        Cell* currentCell = field->getCell(playerPtr->getPosition());
        

        if (currentCell->getHouseLevel() == -1)
        {   
            
            bool choice = playerPtr->getNextMove();
            if(currentCell->getCategory() == "E" && choice)
            {
                playerPtr->buyCell(6, currentCell);
            }
            else if(currentCell->getCategory() == "S" && choice)
            {
                playerPtr->buyCell(10, currentCell);
            }
            else if(currentCell->getCategory() == "L" && choice)
            {
                playerPtr->buyCell(20, currentCell);
            } 
            std::cout << "Il giocatore " << playerPtr->getIndex() << " ha comprato il terreno " << currentCell->getPosition() <<". Il suo bilancio attuale e': " << playerPtr->getBalance() << "." << std::endl;
        }
        
        else
        {
            if (currentCell->getOwnerIndex() == playerPtr->getIndex())
            {
                if(currentCell->getHouseLevel() < 2)
                {
                    bool choice = playerPtr->getNextMove();
                    if (choice) {
                        playerPtr->buyHouse(currentCell);
                        std::cout << "Il giocatore " << playerPtr->getIndex() << " ha comprato una casa. Il suo bilancio attuale e': " << playerPtr->getBalance() << "." << std::endl;
                    }
                }
            }

            else 
            {
                if (currentCell->getHouseLevel() == 2)
                {
                    if (currentCell->getCategory() == "E")
                    {
                        if (playerPtr->hasBalance(4))
                        {
                            playerPtr->payTo(4, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 4 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;

                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell->getCategory() == "S")
                    {
                        if (playerPtr->hasBalance(8))
                        {
                            playerPtr->payTo(8, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 8 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;

                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell->getCategory() == "L")
                    {
                        if (playerPtr->hasBalance(14))
                        {
                            playerPtr->payTo(14, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 14 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;

                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                }

                else if(currentCell->getHouseLevel() == 1)
                {
                    if (currentCell->getCategory() == "E")
                    {
                        if (playerPtr->hasBalance(2))
                        {
                            playerPtr->payTo(2, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 2 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;

                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell->getCategory() == "S")
                    {
                        if (playerPtr->hasBalance(4))
                        {
                            playerPtr->payTo(4, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 4 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;
                        }
                        else
                        {
                            hasMoney = false;
                        }
                    }
                    else if (currentCell->getCategory() == "L")
                    {
                        if (playerPtr->hasBalance(7))
                        {
                            playerPtr->payTo(7, PlayersArr[currentCell->getOwnerIndex() - 1]);
                            std::cout << "Il giocatore " << playerPtr->getIndex() << " pagato 7 al giocatore" << PlayersArr[currentCell->getOwnerIndex() - 1]->getIndex() << "." << std::endl;
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
            players.push(playerPtr);
        }
        
        else
        {
            int indexLoser = playerPtr->getIndex();
            field->removePlayerProperties(indexLoser);
            field->removePlayer(playerPtr->getPosition(), indexLoser); //viene rimosso lo zesty loser
        }
        players.pop();
        field->printMap();
        //sleep(2);
        //system("clear");
        turn_count ++;
    }

    std::cout << "Esecuzione del gioco terminata." << std::endl;
    std::cout << "Il classifica del gioco e\'" << std::endl;
    showRanking(PlayersArr, players.size());

    delete field;
    for(int i = 0; i < 4; i++)
    {
        Player* temp = PlayersArr[i];
        delete temp;
    }
}