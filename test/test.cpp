// TEST NETWORK : CLIENT 1 : HOST SERVER

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "test.h"

using namespace std;

// Number of players randomized since this is test core class
int main()
{
    unsigned int nb = 2;
    MultiplayerGame * game = new MultiplayerGame(nb);
    // host server
    game->createServer();
    printf("\nHello guys\n");

    /*
    // Get number_of_players
        unsigned int nop;
        std::cout << "Combien de joueur ? " << std::endl;
        std::cin >> nop;

        game = new MultiplayerGame(nop);

        while (!game->isEnd())
        {
            game->startRound();
            while (!game->roundFinished())
            {
                Player * p = game->startTurn();
                p->pickCard(*game->getDeck());

                // Show cards to play
                std::cout << "0: " << p->getCard()->getName() << std::endl;
                std::cout << "1: " << p->getCard(1)->getName() << std::endl;

                // Select card to play
                std::cout << "Which card to play ?" << std::endl;
                int play_card;
                std::cin >> play_card;

                if (p->getCard(play_card)->getName() == "Guard") {
                    std::cout << "Choose a target ?" << std::endl;
                    int target;
                    std::cin >> target;
                    std::cout << "Guess a card ?" << std::endl;
                    std::string card;
                    std::cin >> card;

                    game->pickTarget(target);
                    game->guessCard(card);
                }

                p->play(play_card);

                game->update();
            }
        }
    */
}

