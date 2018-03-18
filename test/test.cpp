#include <cstdlib>
#include <ctime>
#include <iostream>

#include "test.h"

using namespace std;

// Number of players randomized since this is test core class
int main()
{
    srand((unsigned)time(0));

    // nbPlayers between 2 and 4
    // normally given by IHM
    int nbPlayers = (rand()%4)+2;

    Game game(nbPlayers);
    game.start();

    // Game loop
    while(game.isOver())
    {
        game.startRound();

        int i = 0;
        while(i != nbPlayers)
        {
            // normally card given by IHM
            game.startTurn(game.getCurrentPlayer().getCard());
            i++;
        }

        game.update();
    }

    // Game's finished

    return 0;
}
