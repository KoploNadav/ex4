//
// Created by Nadav Koplovich on 11/06/2022
//

#include "Dragon.h"

Dragon::Dragon():
        BattleCard("Dragon", 25, 1000, std::numeric_limits<int>::max(), 0)
{}

void Dragon::printCard(std::ostream &os, Card &card)
{
    printCardDetails(os, card.getName());
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins, true);
    printEndOfCardDetails(os);
}