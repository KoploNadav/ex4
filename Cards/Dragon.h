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

    Dragon& operator=(const Dragon&) = default;

    ~Dragon() = default;
};



#endif //EX4_DRAGON_H
