//
// Created by Nadav Koplovich on 08/06/2022
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
public:
    Fighter(string name);

    Fighter(const Fighter&) = default;

    Fighter& operator=(const Fighter&) = default;

    ~Fighter() = default;

    int getAttackStrength() const override;
};

#endif //EX4_FIGHTER_H
