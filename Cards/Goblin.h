//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "BattleCard.h"

class Goblin : public BattleCard
{
public:
    Goblin();

    Goblin(const Goblin&) = default;

    void test(int test);
};

#endif //EX4_GOBLIN_H
