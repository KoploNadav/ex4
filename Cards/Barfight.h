//
// Created by Nadav Koplovich on 11/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card
{
    Barfight();

    void applyEncounter(Player &player) const override;
};


#endif //EX4_BARFIGHT_H
