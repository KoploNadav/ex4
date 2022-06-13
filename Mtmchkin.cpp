//
// Created by Nadav Koplovich on 11/06/2022.
//

#include <fstream>
#include <iostream>
#include <regex>

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


void split(string& original, string &name, string &job)
{
    int spaceIndex = original.find(' ');
    name = original.substr(0, spaceIndex);
    if(spaceIndex > -1){
        job = original.substr(spaceIndex + 1);
    }
};

bool isValidPlayerName(string name)
{
    if(name.length() > 15){
        return false;
    }
    return std::regex_match(name, std::regex("^[A-Za-z]+$"));
};

bool isValidJobName(string name)
{
    if(name != "Fighter" && name != "Rogue" && name != "Wizard"){
        return false;
    }
    return true;
};

Mtmchkin::Mtmchkin(const std::string fileName):
    m_round(0),
    m_currentCard(0),
    m_numOfWinners(0),
    m_numOfLosers(0)
{
    string cardName;

    std::ifstream file(fileName);
    if(file.fail()) {
        throw DeckFileNotFound();
    }
    int lineCounter = 1;
    while(getline(file, cardName)){
        if(cardName == "Fairy") {
            Fairy* fairy = new Fairy();
            this->m_cards.push_back(fairy);
        }
        else if(cardName == "Goblin") {
            Goblin* goblin = new Goblin();
            this->m_cards.push_back(goblin);
        }
        else if(cardName == "Vampire") {
            Vampire* vampire = new Vampire();
            this->m_cards.push_back(vampire);
        }
        else if(cardName == "Barfight") {
            Barfight* barfight = new Barfight;
            this->m_cards.push_back(barfight);
        }
        else if(cardName == "Dragon") {
            Dragon* dragon = new Dragon;
            this->m_cards.push_back(dragon);
        }
        else if(cardName == "Treasure") {
            Treasure* treasure = new Treasure;
            this->m_cards.push_back(treasure);
        }
        else if(cardName == "Merchant") {
            Merchant* merchant = new Merchant;
            this->m_cards.push_back(merchant);
        }
        else if(cardName == "Pitfall") {
            Pitfall* pitfall = new Pitfall;
            this->m_cards.push_back(pitfall);
        }
        else {
            throw DeckFileFormatError(lineCounter);
        }
        lineCounter++;
    }

    if (lineCounter < 5){
        throw DeckFileInvalidSize();
    }
    file.close();

    printStartGameMessage();
    string size;
    printEnterTeamSizeMessage();
    int intSize = 0;
    while(std::cin >> size){
        try{
            intSize = stoi(size);
            if (intSize >= 2 && intSize <= 6){
                printInvalidTeamSize();
                break;
            }
        }
        catch(std::invalid_argument &e){
            printInvalidTeamSize();
        } 
    }
    string playerNameAndClass;
    for(int i = 0; i < intSize; i++){
        printInsertPlayerMessage();
        string name, job;
        while(std::getline(std::cin, playerNameAndClass)) {
            split(playerNameAndClass, name, job);
            if(isValidPlayerName(name)) {
                printInvalidName();
            }
            else if(isValidJobName(job)){
                printInvalidClass();
            }
            else{
                break;
            }
        }
        if(job == "Fighter") {
            Fighter* fighter = new Fighter(name);
            this->m_players.push_back(fighter);
        }
        if(job == "Rogue") {
            Rogue* rogue = new Rogue(name);
            this->m_players.push_back(rogue);
        }
        else{
            Wizard* wizard = new Wizard(name);
            this->m_players.push_back(wizard);
        }
    }
}

void Mtmchkin::playRound()
{
    this->m_round++;
    printRoundStartMessage(this->m_round);
    for(int i = 0; i < this->m_players.size(); i++) {
        if (!this->m_players[i]->isPlaying()) {
            continue;
        }
        printTurnStartMessage(this->m_players[i]->getName());
        this->m_cards[this->m_currentCard]->applyEncounter(*this->m_players[i]);
        this->m_currentCard++;
        if(this->m_currentCard >= this->m_cards.size()) {
            this->m_currentCard = 0;
        }

        if(this->m_players[i]->isKnockedOut()){
            Player* temp(this->m_players[i]);
            this->m_players.erase(this->m_players.begin() + (i-1));
            this->m_players.insert((this->m_players.begin()) + (this->m_players.size() - this->m_numOfLosers), temp);
            this->m_numOfLosers++;
        }
        else if(this->m_players[i]->getLevel() == 10){
            Player* temp(this->m_players[i]);
            this->m_players.erase(this->m_players.begin() + (i-1));
            this->m_players.insert((this->m_players.begin())  + (this->m_numOfWinners), temp);
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
    for(int i = 1; i <= this->m_players.size(); i++){
        printPlayerLeaderBoard(i, *this->m_players[i]);
    }
}

bool Mtmchkin::isGameOver() const
{
    for(int i =0; i < this->m_players.size(); i++){
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
