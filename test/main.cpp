// TEST NETWORK : CLIENT 1 : HOST SERVER
// MESSAGE FORMAT "xyz"
    // x = Index of Played Card
    // y = Index of Targeted Player ==> OPTIONAL
    // z = Name of guessed card ==> OPTIONAL / GUARD ONLY

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> //atoi
#include <iostream> //to_string
#include "test.h"

using namespace std;

int main()
{
    unsigned int nb = 2;
    MultiplayerGame * game = new MultiplayerGame(nb);

    string rec = ""; //received string from servers

    // I will be the player 1
    int myNumber = 0;

    // Host server - COMMENTED FOR TEST PURPOSE - TO UNCOMMENT
        //game->createServer();

    // Init connection
    //TCPClient * tcp = new TCPClient();

    // Connect localhost cause we host the server
    game->joinServer("127.0.0.1");


    // Locally start the game
    while (!game->gameOver())
    {
        game->startRound();


        // Build string to send to server
        Core::Deck * d = game->getDeck();
        string deck = "";
        // add first letter of each card
            // priest = p; prince = y ; princess = z ;

        //printf("AVANT LE FOR !\n");
        string card = "";
        // NOT WORKING !
        for(std::list<Core::Card *>::iterator it = d->getCards().begin(); it != d->getCards().end(); ++it){

            //printf("DANS LE FOR !\n");
            //cout << "card : \n" + (*it)->getName().at(0) << "\n";
            card = (*it)->getName();
            char f = card.at(0);
            //printf("card full name : %s \n", card);
            printf("first letter : %c \n", f);

            // ------ DEBUG ----------------
            return 0;

            deck += (*it)->getName();
        }



        // Send Deck to server
        game->getTCP().Send(deck);
        //tcp->Send(deck);



        while (!game->roundOver())
        {
            // If it's not my turn, I wait for server to tell me smth
            if(game->getCurrentPlayerIndex() != myNumber){
                rec = game->getTCP().receive();

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
                game->getTCP().Send(rec);
            }

        }
    }
}

