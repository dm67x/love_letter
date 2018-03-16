#include "test.h"

using namespace std;

int main()
{
    // Create a game with 2 players

    // nbPlayers given by IHM
    int nbPlayers = 2;

    Game game = new Game(nbPlayers);
    game.start();

    // Game loop
    while(game.isOver())
    {
        game.startRound();

        int i = 0;
        while(i != nbPlayers)
        {
            // Card given by IHM
            // so there is still an error here
            game.startTurn();

            // Should I update after each turn ?
            game.update();
            i++;
        }
    }

    return 0;
}
