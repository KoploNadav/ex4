//
// Created by Daniel_Meents on 07/04/2022
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include <iostream>
#include "../Players/Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has a type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
//enum class CardType {Barfight, Dragon, Fairy, Goblin, Merchant, Pitfall, Treasure, Vampire}; // The type of the Card

class Card 
{
virtual void printCard(std::ostream &os, Card &card);

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
     * Copy C'tor
     *
     * @param other - Card to copy from.
     * @return a copy of the card
     */
    Card(const Card& other);

    /*
     * @brief Assignment operator. Assign Card object from another Card
     *
     * @param other Another Card to assign from
     * @return Returns the newly assigned Card
     */
    Card& operator=(const Card& other);

    /**
    * @brief Destructs a card
    */
    virtual ~Card() = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    /**
     * @brief Get the Name of the card
     *
     * @return Returns the Name of the card
     */
    virtual std::string getName() const;


    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    //Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;

    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    /*
     * Prints the card info:
     *
    */
    friend std::ostream& operator<<(std::ostream& os, Card &card);

protected:
    std::string m_name;

};


#endif //EX2_Card_H