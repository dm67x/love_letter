#include <cstdlib>
#include <ctime>
#include <iostream>

#include "test.h"

using namespace std;

/* Number of players randomized since this is test
 * core class, same with cards choice
 */
int main()
{
    srand((unsigned)time(0));

    // nbPlayers between 2 and 4
    // normally given by IHM
    int nbPlayers = (rand()%4)+2;

    Game game = new Game(nbPlayers);
    game.start();

    // Game loop
    while(game.isOver())
    {
        game.startRound();

        int i = 0;
        while(i != nbPlayers)
        {
            // normally given by IHM
            // can randomize it but needs current player
            // to get current player's cards
            // so there is an error here
            game.startTurn();

            // Should I update after each turn ?
            game.update();
            i++;
        }
    }

    return 0;
}
