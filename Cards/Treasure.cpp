//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Treasure.h"

Treasure::Treasure():
Card("Treasure")
{}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(10);
    printTreasureMessage();
}

