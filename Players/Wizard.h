//
// Created by Nadav Koplovich on 08/06/2022
//

#include "Player.h"

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

class Wizard : public Player
{
public:
    Wizard(string name);

    Wizard(const Wizard&) = default;

    Wizard& operator=(const Wizard&) = default;

    ~Wizard() = default;

    void heal(int hp) override;
};

#endif //EX4_WIZARD_H
