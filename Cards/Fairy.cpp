//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Fairy.h"

Fairy::Fairy():
Card("Fairy")
{}

void Fairy::applyEncounter(Player &player) const 
{
    if(player.getJob() != "Wizard"){
        printFairyMessage(false);
    }
    else{
        player.heal(10);
        printFairyMessage(true);
    }

}
