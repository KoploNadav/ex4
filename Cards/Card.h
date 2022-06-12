//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include <iostream>
#include "Players/Player.h"
#include "utilities.h"

/*
 *  CardType:
 *  Each card has a type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
//enum class CardType {Barfight, Dragon, Fairy, Goblin, Merchant, Pitfall, Treasure, Vampire}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(std::string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const;


    /**
     * @brief Get the Name of the card
     *
     * @return Returns the Name of the card
     */
    std::string getName() const;


    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    //Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;

    Card();

    ~Card() = default;
    Card& operator=(const Card& other) = default;

    /*
     * Prints the card info:
     *
    */
    std::ostream& operator<<(std::ostream& os){
        printCardDetails(os, this->m_name);
        printEndOfCardDetails(os);
    };

protected:
    std::string m_name;
    //CardStats m_stats;

};


#endif //EX2_Card_H