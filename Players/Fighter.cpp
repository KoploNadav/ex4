//
// Created by Nadav Koplovich on 08/06/2022.
//

#include "Fighter.h"

int Fighter::getAttackStrength() const {
    return 2 * this->m_force + this->m_level;
}