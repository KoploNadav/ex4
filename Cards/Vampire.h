//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "BattleCard.h"

class Vampire : public BattleCard
{
public:
    Vampire();

    Vampire(const Vampire&) = default;

    void applyEncounter(Player &player) const override;
};


#endif //EX4_VAMPIRE_H
