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

    virtual ~BattleCard() = default;

    void applyEncounter(Player &player) const override;
};


#endif //EX4_BATTLECARD_H
