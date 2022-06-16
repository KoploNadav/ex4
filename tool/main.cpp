#include "../Players/Player.h"
#include "../Cards/Card.h"
#include "../Mtmchkin.h"

using std::cout;
using std::endl;

int main()
{
    try {
        Mtmchkin game("../deck.txt");
        while (!game.isGameOver())
        {
            game.playRound();
        }
    }
    catch(const std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}