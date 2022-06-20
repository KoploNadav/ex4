//
// Created by Nadav Koplovich on 11/06/2022
//

#include "BattleCard.h"

BattleCard::BattleCard(std::string name, int force, int coins, int damage, int debuff):
    Card(name),
    m_force(force),
    m_coins(coins),
    m_damage(damage),
    m_debuff(debuff)
{}

BattleCard::BattleCard(const BattleCard& other):
        m_name(other.getName()),
        m_force(other.getForce()),
        m_coins(other.getCoins()),
        m_damage(other.getDamage()),
        m_debuff(other.getDebuff())
{}

BattleCard& BattleCard::operator=(const BattleCard& other)
{
    this->m_name = other.getName();
    this->m_force = other.getForce();
    this->m_coins = other.getCoins();
    this->m_damage = other.getDamage();
    this->m_debuff = other.getDebuff();
    return *this;
}

void BattleCard::applyEncounter(Player &player) const 
{
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->m_damage);
        player.buff(-(this->m_debuff));
        printLossBattle(player.getName(), this->m_name);
    }
}

void BattleCard::printCard(std::ostream &os, Card &card)
{
    printCardDetails(os, card.getName());
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins,false);
    printEndOfCardDetails(os);
}

int BattleCard::getForce() const
{
    return this->m_force;
}

int BattleCard::getCoins() const
{
    return this->m_coins;
}

int BattleCard::getDamage() const
{
    return this->m_damage;
}

int BattleCard::getDebuff() const
{
    return this->m_debuff;
}