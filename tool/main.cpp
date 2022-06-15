#include "../Players/Player.h"
#include "../Cards/Card.h"
#include "../Mtmchkin.h"

int main()
{   
    try {
        Mtmchkin game("deck.txt");
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