#include <string>
#include <iostream>
#include "Player.h"
#include "../utilities.h"


using std::cout;
using std::endl;

using std::string;

Player::Player(string name, string job, int maxHP, int force):
        m_name(name),
        m_job(job),
        m_level(1),
        m_force(force),
        m_maxHP(maxHP),
        m_hp(m_maxHP),
        m_coins(0)
{
    if(maxHP <= 0) {
        this->m_maxHP = DEFAULT_MAX_HP;
    }
    if(force <= 0) {
        this->m_force = DEFAULT_FORCE;
    }
}

Player::Player(const Player& other):
        m_name(other.m_name),
        m_job(other.m_job),
        m_level(other.m_level),
        m_force(other.m_force),
        m_maxHP(other.m_maxHP),
        m_hp(other.m_hp),
        m_coins(other.m_coins)
{}

Player& Player::operator=(const Player& other)
{
    if(this == &other) {
        return *this;
    }
    this->m_job = other.m_job;
    this->m_name = other.m_name;
    this->m_level = other.m_level;
    this->m_force = other.m_force;
    this->m_maxHP = other.m_maxHP;
    this->m_hp = other.m_hp;
    this->m_coins = other.m_coins;
    return *this;
}

void Player::levelUp() 
{
    if(this->m_level == MAX_LEVEL){
        return;
    }
    this->m_level++;
}

int Player::getLevel() const 
{
    return this->m_level;
}

void Player::buff(int force) 
{
    this->m_force += force;
}

void Player::heal(int hp) 
{
    if(hp <= 0) {
        return;
    }
    if(this->m_hp + hp >= this->m_maxHP) {
        this->m_hp = this->m_maxHP;
        return;
    }
    this->m_hp += hp;
}

void Player::damage(int hp) 
{
    if(hp <= 0) {
        return;
    }
    if(this->m_hp - hp <= 0) {
        this->m_hp = 0;
        return;
    }
    this->m_hp -= hp;
}

bool Player::isKnockedOut() const 
{
    return this->m_hp == 0;
}

bool Player::isPlaying() const
{
    return this->isKnockedOut() && this->getLevel() == 10;
}

void Player::addCoins(int coins) 
{
    if(coins <= 0) {
        return;
    }
    this->m_coins += coins;
}

bool Player::pay(int price) 
{
    if(price <= 0) {
        return true;
    }
    if(this->m_coins < price) {
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() const 
{
    return this->m_force + this->m_level;
}

int Player::getHP() const 
{
    return this->m_hp;
}

int Player::getCoins() const 
{
    return this->m_coins;
}

std::string Player::getJob() const 
{
    return this->m_job;
}

std::string Player::getName() const 
{
    return this->m_name;
}

std::ostream& operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.m_name, player.m_job, player.m_level, player.m_force, player.m_hp, player.m_coins);
    return os;
}