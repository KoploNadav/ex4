//
// Created by Nadav Koplovich on 08/06/2022
//

#include "Wizard.h"

Wizard::Wizard(string name):
    Player(name , "Wizard")
{}

void Wizard::heal(int hp) 
{
    if(hp <= 0) {
        return;
    }
    if(this->m_hp + 2 * hp >= this->m_maxHP) {
        this->m_hp = this->m_maxHP;
        return;
    }
    this->m_hp += 2 * hp;
}