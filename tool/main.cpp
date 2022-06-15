#include "../Players/Player.h"
#include "../Cards/Card.h"
#include "../Mtmchkin.h"
#include "../Cards/Dragon.h"

int main()
{   
    Card* card = new Dragon();
    std::cout << card << std::endl;

    try {
        Mtmchkin game("../deck.txt");
        while (!game.isGameOver())
        {
            game.playRound();
        }
    }
    catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}