//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Dragon.h"

Dragon::Dragon():
        BattleCard("Dragon", 25, 1000, 0)
{}

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
    }
    else{
        player.damage(player.getHP());
    }
}

