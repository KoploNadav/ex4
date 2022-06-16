//
// Created by Nadav Koplovich on 11/06/2022
//

#include "Merchant.h"

Merchant::Merchant():
Card("Merchant")
{}

void Merchant::applyEncounter(Player &player) const 
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    string input;
    while(std::getline(std::cin, input)){
        bool validInput = false;
        try{
            switch(stoi(input)) {
                case 0:
                    printMerchantSummary(std::cout, player.getName(), 0, 0);
                    validInput = true;
                    break;
                case 1:
                    if(player.pay(5)){
                        player.heal(1);
                        printMerchantSummary(std::cout, player.getName(), 1, 5);
                    }
                    else{
                        printMerchantInsufficientCoins(std::cout);
                        printMerchantSummary(std::cout, player.getName(), 1, 0);
                    } 
                    validInput = true;
                    break;
                case 2:
                    if(player.pay(10)){
                        player.buff(1);
                        printMerchantSummary(std::cout, player.getName(), 2, 10);
                    }
                    else{
                        printMerchantInsufficientCoins(std::cout);
                        printMerchantSummary(std::cout, player.getName(), 2, 0);
                    }
                    validInput = true;
                    break;
                default:
                    printInvalidInput();
                    break;
            }
        }
        catch(std::invalid_argument &e){
            printInvalidInput();
        } 
        if(validInput){
            break;
        }
    }
}