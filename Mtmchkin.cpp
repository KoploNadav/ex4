//
// Created by Nadav Koplovich on 11/06/2022.
//

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <algorithm>

#include "Mtmchkin.h"
#include "Cards/Card.h"
#include "Players/Player.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "CardMap.h"

using std::shared_ptr;




void split(string& original, string &name, string &job)
{
    int spaceIndex = original.find(' ');
    name = original.substr(0, spaceIndex);
    if(spaceIndex > -1){
        job = original.substr(spaceIndex + 1);
    }
}

bool isValidPlayerName(string name)
{
    if(name.length() > 15) {
        return false;
    }
    for(unsigned long int i=0; i < name.length(); i++) {
        char c = name[i];
        if(!((c >= 'A' && c <= 'Z') || (c >= 'a' || c <= 'z'))) {
            return false;
        }
    }
    return true;
}

bool isValidJobName(string name)
{
    if(name != "Fighter" && name != "Rogue" && name != "Wizard"){
        return false;
    }
    return true;
}

Mtmchkin::Mtmchkin(const std::string fileName):
    m_round(0),
    m_currentCard(0),
    m_numOfWinners(0),
    m_numOfLosers(0)
{
    printStartGameMessage();
    string cardName;
    std::ifstream file(fileName);
    if(file.fail()) {
        throw DeckFileNotFound();
    }
    int lineCounter = 1;
    while(getline(file, cardName)){
        if(cardMap.find(cardName) == cardMap.end()) {
            throw DeckFileFormatError(lineCounter);
        }
        this->m_cards.push_back(cardMap[cardName]);
        lineCounter++;
        /*if(cardName == "Fairy") {
            shared_ptr<Card> fairy(new Fairy());
            this->m_cards.push_back(fairy);
        }
        else if(cardName == "Goblin") {
            shared_ptr<Card> goblin(new Goblin());
            this->m_cards.push_back(goblin);
        }
        else if(cardName == "Vampire") {
            shared_ptr<Card> vampire(new Vampire());
            this->m_cards.push_back(vampire);
        }
        else if(cardName == "Barfight") {
            shared_ptr<Card> barfight(new Barfight());
            this->m_cards.push_back(barfight);
        }
        else if(cardName == "Dragon") {
            shared_ptr<Card> dragon(new Dragon());
            this->m_cards.push_back(dragon);
        }
        else if(cardName == "Treasure") {
            shared_ptr<Card> treasure(new Treasure());
            this->m_cards.push_back(treasure);
        }
        else if(cardName == "Merchant") {
            shared_ptr<Card> merchant(new Merchant());
            this->m_cards.push_back(merchant);
        }
        else if(cardName == "Pitfall") {
            shared_ptr<Card> pitfall(new Pitfall());
            this->m_cards.push_back(pitfall);
        }
        else {
            throw DeckFileFormatError(lineCounter);
        }*/
        
    }
    if (lineCounter-1 < 5){
        throw DeckFileInvalidSize();
    }
    file.close();
    string size;
    printEnterTeamSizeMessage();
    int intSize = 0;
    while(std::cin >> size){
        try{
            intSize = stoi(size);
            if (intSize >= 2 && intSize <= 6){
                break;
            }
            printInvalidTeamSize();
        }
        catch(std::invalid_argument &e){
            printInvalidTeamSize();
        } 
    }
    std::cin.ignore();
    string playerNameAndClass;
    for(int i = 0; i < intSize; i++){
        printInsertPlayerMessage();
        string name, job;
        while(std::getline(std::cin, playerNameAndClass)) {
            split(playerNameAndClass, name, job);
            if(!isValidPlayerName(name)) {
                printInvalidName();
            }
            else if(!isValidJobName(job)){
                printInvalidClass();
            }
            else{
                break;
            }
        }
        if(job == "Fighter") {
            shared_ptr<Player> fighter(new Fighter(name));
            this->m_players.push_back(fighter);
            this->m_leaderboard.push_back(fighter);
        }
        else if(job == "Rogue") {
            shared_ptr<Player> rogue(new Rogue(name));
            this->m_players.push_back(rogue);
            this->m_leaderboard.push_back(rogue);
        }
        else if(job == "Wizard"){
            shared_ptr<Player> wizard(new Wizard(name));
            this->m_players.push_back(wizard);
            this->m_leaderboard.push_back(wizard);
        }
    }
}

void Mtmchkin::playRound()
{
    this->m_round++;
    printRoundStartMessage(this->m_round);
    for(unsigned int i = 0; i < this->m_players.size(); i++) {
        if (!(this->m_players[i]->isPlaying())) {
            continue;
        }
        printTurnStartMessage(this->m_players[i]->getName());
        this->m_cards[this->m_currentCard]->applyEncounter(*this->m_players[i]);
        this->m_currentCard++;
        if(this->m_currentCard >= this->m_cards.size()) {
            this->m_currentCard = 0;
        }

        if(this->m_players[i]->isKnockedOut()){
            shared_ptr<Player> temp(this->m_players[i]);
            this->m_leaderboard.erase(std::remove(this->m_leaderboard.begin(), this->m_leaderboard.end(), temp), this->m_leaderboard.end());
            this->m_leaderboard.insert((this->m_leaderboard.end()) - (this->m_numOfLosers), temp);
            this->m_numOfLosers++;
        }
        else if(this->m_players[i]->getLevel() == 10){
            shared_ptr<Player> temp(this->m_players[i]);
            this->m_leaderboard.erase(std::remove(this->m_leaderboard.begin(), this->m_leaderboard.end(), temp), this->m_leaderboard.end());
            this->m_leaderboard.insert((this->m_leaderboard.begin()) + (this->m_numOfWinners), temp);
            this->m_numOfWinners++;
        }

    }
    if(isGameOver()) {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for(unsigned int i = 1; i <= this->m_leaderboard.size(); i++){
        printPlayerLeaderBoard(i, *this->m_leaderboard[i-1]);
    }
}

bool Mtmchkin::isGameOver() const
{
    for(unsigned int i =0; i < this->m_players.size(); i++){
        if(this->m_players[i]->isPlaying()){
            return false;
        }
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return this->m_round;
}
