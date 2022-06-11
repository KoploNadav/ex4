//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Barfight.h"

Barfight::Barfight():
Card("Barfight")
{}

void Barfight::applyEncounter(Player &player) const {
    if(player.getJob() != "Fighter"){
        player.damage(10);
        printBarfightMessage(false);
    }
    else{
        printBarfightMessage(true);
    }
}