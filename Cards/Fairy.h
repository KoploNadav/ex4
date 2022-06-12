//
// Created by Nadav Koplovich on 11/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card
{
    Fairy();

    void applyEncounter(Player &player) const override;
};



#endif //EX4_FAIRY_H
