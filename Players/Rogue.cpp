//
// Created by Nadav Koplovich on 08/06/2022.
//
#include "Rogue.h"

void Rogue::addCoins(int coins) {
    if(coins <= 0) {
        return;
    }
    this->m_coins += 2 * coins;
}
