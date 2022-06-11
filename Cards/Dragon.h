//
// Created by Nadav Koplovich on 11/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard{
public:
    Dragon();

    void applyEncounter(Player &player) const override;

    std::ostream& operator<<(std::ostream& os){
        printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins,true);
    }
};



#endif //EX4_DRAGON_H
