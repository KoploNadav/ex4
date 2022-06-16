//
// Created by Nadav Koplovich on 11/06/2022
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card
{
public:
    Merchant();

    Merchant(const Merchant&) = default;

    void applyEncounter(Player &player) const override;
};

#endif //EX4_MERCHANT_H
