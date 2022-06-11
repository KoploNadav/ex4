//
// Created by Nadav Koplovich on 11/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():
Card("Merchant")
{}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int input;
    std::cin >> input;
    while(input != 0 && input != 1 && input != 2){
        printInvalidInput();
        std::cin >> input;
    }
    if(input == 1){
        if(player.pay(5)){
            player.heal(1);
            printMerchantSummary(std::cout, player.getName(), 1, 5);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(input == 2){
        if(player.pay(10)){
            player.buff(1);
            printMerchantSummary(std::cout, player.getName(), 2, 10);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else{
        printMerchantSummary(std::cout, player.getName(), 0, 0);
    }
}