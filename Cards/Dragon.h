//
// Created by Nadav Koplovich on 11/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard
{
public:
    Dragon();

    Dragon(const Dragon&) = default;

    void applyEncounter(Player &player) const override;

    std::ostream& operator<<(std::ostream& os)
    {
        printCardDetails(os, this->m_name);
        printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins,true);
        return os;
    }
};



#endif //EX4_DRAGON_H
