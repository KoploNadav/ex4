//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Pitfall.h"

Pitfall::Pitfall():
Card("Pitfall")
{}

void Pitfall::applyEncounter(Player &player) const {
    if (player.getJob() != "Rogue"){
        player.damage(10);
    }
}