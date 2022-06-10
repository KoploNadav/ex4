//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "BattleCard.h"

BattleCard::BattleCard(std::string name, int force, int coins, int damage):
    m_force(force),
    m_damage(damage),
    m_coins(coins),
    Card(name)
{}

void BattleCard::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
    }
    else{
        player.damage(this->m_damage);
    }
}
