//
// Created by Nadav Koplovich on 11/06/2022
//

#include <limits>

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard
{
    void printCard(std::ostream &os, Card &card) override;

public:
    Dragon();

    Dragon(const Dragon&) = default;

    void applyEncounter(Player &player) const override;

};



#endif //EX4_DRAGON_H
