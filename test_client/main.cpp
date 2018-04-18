// TEST NETWORK : CLIENT 1 : CONNECT TO SERVER
// TODO

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include "../network/multiplayergame.h"

using namespace std;

int main()
{
    unsigned int nb = 2;
    MultiplayerGame * game = new MultiplayerGame(nb);
    // host server
    //game->createServer();

    string rec = "";

    // Init connection
    TCPClient * tcp = new TCPClient();

    int myNumber = game->joinServer("127.0.0.1"); //1 //2
    printf("my number : %d \n",myNumber);

    return 0;

    // OTHER GUY CONNECTS
    // I AM THE PLAYER 1

    // Locally start the game
    while (!game->gameOver())
    {
        game->startRound();
        // Receive the Deck from Server
        string deck = tcp->receive();

        while (!game->roundOver())
        {
            // If it's not my turn, I wait for server to tell me smth
            if(game->getCurrentPlayerIndex() != myNumber){
                rec = tcp->receive();

                if(rec.length() < 1){
                    // MUST THROW AN ERROR
                }
                // Reproduce on my local game what happened on the others
                Core::Player * p = game->startTurn();
                p->pickCard();

                // Played Card
                if(rec.length() == 1){
                    p->discard(atoi(rec.c_str()));
                }

                // Played Card + Target
                if(rec.length() == 2){
                    game->pickTarget(rec.at(1));
                    p->discard(int(rec.at(0)));
                }

                // Played Card + Target + Guessed Card
                if(rec.length() == 3){
                    game->pickTarget(rec.at(1));
                    game->guessCard(rec.substr(2));
                    p->discard(int(rec.at(0)));
                }

            // It is my turn
            }else{
                rec = ""; //use this to send server infos

                Core::Player * p = game->startTurn();
                p->pickCard();

                // Show cards to play
                std::cout << "0: " << p->getCard()->getName() << std::endl;
                std::cout << "1: " << p->getCard(1)->getName() << std::endl;

                // Select card to play
                std::cout << "Which card to play ?" << std::endl;
                int play_card;
                std::cin >> play_card;

                rec += ""+play_card; // send to server

                if (p->getCard(play_card)->getName() == "Guard") {
                    std::cout << "Choose a target ?" << std::endl;
                    int target;
                    std::cin >> target;

                    rec += ""+play_card; // send to server

                    std::cout << "Guess a card ?" << std::endl;
                    std::string card;
                    std::cin >> card;

                    rec += ""+card; // send to server

                    game->pickTarget(target);
                    game->guessCard(card);
                }

                p->discard(play_card);

                game->update();

                // SEND INFO TO SERVER
                tcp->Send(rec);
            }

        }
    }

}
