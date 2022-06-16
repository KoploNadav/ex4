//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card
{
public:
    Pitfall();

    Pitfall(const Pitfall&) = default;

    void applyEncounter(Player &player) const override;
};


#endif //EX4_PITFALL_H
