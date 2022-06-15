//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Dragon.h"

Dragon::Dragon():
        BattleCard("Dragon", 25, 1000, 0)
{}

void Dragon::applyEncounter(Player &player) const 
{
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(player.getHP());
        printLossBattle(player.getName(), this->m_name);
    }
}

void BattleCard::printCard(std::ostream &os, Card &card)
{
    printCardDetails(os, card.getName());
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins, true);
    printEndOfCardDetails(os);
}