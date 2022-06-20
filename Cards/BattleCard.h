//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card{
    virtual void printCard(std::ostream &os, Card &card) override;

protected:
    const int m_force;
    const int m_coins;
    const int m_damage;
    const int m_debuff;

public:
    BattleCard(std::string name, int force, int coins, int damage, int debuff);

    BattleCard(const BattleCard& other);

    BattleCard& operator=(const BattleCard& other);

    virtual ~BattleCard() = default;

    void applyEncounter(Player &player) const override;

    /**
     * @brief Get the force of the card
     *
     * @return Returns the force of the card
     */
    int getForce() const;

    /**
     * @brief Get the coins of the card
     *
     * @return Returns the coins of the card
     */
    int getCoins() const;

    /**
     * @brief Get the damage of the card
     *
     * @return Returns the damage of the card
     */
    int getDamage() const;

    /**
     * @brief Get the debuff of the card
     *
     * @return Returns the debuff of the card
     */
    int getDebuff() const;
};


#endif //EX4_BATTLECARD_H
