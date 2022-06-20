//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card
{
public:
    Barfight();

    Barfight(const Barfight& other) = default;

    Barfight& operator=(const Barfight&) = default;

    ~Barfight() = default;

    void applyEncounter(Player &player) const override;
};

#endif //EX4_BARFIGHT_H
