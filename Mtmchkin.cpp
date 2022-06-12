//
// Created by Nadav Koplovich on 11/06/2022.
//

#include <fstream>
#include <iostream>
#include <regex>

#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

Mtmchkin::Mtmchkin(const std::string fileName)
{
    string cardName;
    std::ifstream file(fileName);
    while(getline(file, cardName)){
        this->m_cards.push(Card(cardName));
    }
    file.close();

    printStartGameMessage();
    int size;
    printEnterTeamSizeMessage();
    std::cin >> size;
    while(size > 6 || size < 2){
        printInvalidTeamSize();
        std::cin >> size;
    }
    string playerNameAndClass;
    for(int i = 0; i < size; i++){
        printInsertPlayerMessage();
        std::getline(std::cin, playerNameAndClass);

    }
}

bool isValidPlayerName(string name){
    if(name.length() > 15){
        return false;
    }
    return !std::regex_match(name, std::regex("^[A-Za-z]+$"));
}

bool isValidClassName(string name){
    if(name != "Fighter" && name != "Rogue" && name != "Wizard"){
        return false;
    }
    return true;
}
