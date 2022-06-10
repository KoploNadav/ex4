#include <string>
#include <cstring>
#include <iostream>
#include "Player.h"
#include "utilities.h"

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
        m_level(other.m_level),
        m_force(other.m_force),
        m_maxHP(other.m_maxHP),
        m_hp(other.m_hp),
        m_coins(other.m_coins)
{}

Player& Player::operator=(const Player& other){
    if(this == &other) {
        return *this;
    }
    this->m_name = other.m_name;
    this->m_level = other.m_level;
    this->m_force = other.m_force;
    this->m_maxHP = other.m_maxHP;
    this->m_hp = other.m_hp;
    this->m_coins = other.m_coins;
    return *this;
}

void Player::printInfo() const {
    char* name = strcpy(new char[this->m_name.length()+1], this->m_name.c_str());
    printPlayerInfo(name, this->m_level, this->m_force, this->m_hp, this->m_coins);
    delete[] name;
}

void Player::levelUp() {
    if(this->m_level == MAX_LEVEL){
        return;
    }
    this->m_level++;
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int force) {
    if(force <= 0) {
        return;
    }
    this->m_force += force;
}

void Player::heal(int hp) {
    if(hp <= 0) {
        return;
    }
    if(this->m_hp + hp >= this->m_maxHP) {
        this->m_hp = this->m_maxHP;
        return;
    }
    this->m_hp += hp;
}

void Player::damage(int hp) {
    if(hp <= 0) {
        return;
    }
    if(this->m_hp - hp <= 0) {
        this->m_hp = 0;
        return;
    }
    this->m_hp -= hp;
}

bool Player::isKnockedOut() const {
    return this->m_hp == 0;
}

void Player::addCoins(int coins) {
    if(coins <= 0) {
        return;
    }
    this->m_coins += coins;
}

bool Player::pay(int price) {
    if(price <= 0) {
        return true;
    }
    if(this->m_coins < price) {
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}

ostream& Player::operator<<(std::ostream &os) {
    printPlayerDetails(&os, this->m_name, this->m_job, this->m_level, this->m_force, this->m_hp, this->m_coins)
}