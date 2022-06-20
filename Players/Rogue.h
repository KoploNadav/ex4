//
// Created by Nadav Koplovich on 08/06/2022
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"

class Rogue : public Player
{
public:
    Rogue(string name);

    Rogue(const Rogue&) = default;

    Rogue& operator=(const Rogue&) = default;

    ~Rogue() = default;

    void addCoins(int coins) override;
};

#endif //EX4_ROGUE_H
