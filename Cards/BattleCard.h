//
// Created by Nadav Koplovich on 11/06/2022.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card{
protected:
    const int m_force;
    const int m_damage;
    const int m_coins;

public:
    BattleCard(std::string name, int force, int coins, int damage);

    void applyEncounter(Player &player) const override;

    std::ostream& operator<<(std::ostream& os){
        printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins,false);
    }
};


#endif //EX4_BATTLECARD_H
