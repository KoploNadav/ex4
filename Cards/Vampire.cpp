//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Vampire.h"

Vampire::Vampire():
        BattleCard("Vampire", 10, 2, 10)
{}

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->m_damage);
        player.buff(-1);
        printLossBattle(player.getName(), this->m_name);
    }
}