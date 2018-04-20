// TEST NETWORK : CLIENT 1 : CONNECT TO SERVER
// TODO

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QtDebug>
#include "../network/multiplayergame.h"

using namespace std;

int main()
{
    printf("hello ! \n");

    unsigned int nb = 2;
    MultiplayerGame * game = new MultiplayerGame(nb);

    string rec = "";

    int myNumber = game->joinServer("127.0.0.1"); //1 //2
    qDebug() << "myNumber : " << myNumber;

    //int test = game->receiveServer();
    //qDebug() << "test passed : \n";
    //qDebug() << test;
    //printf("test = %s\n",test);


    // OTHER GUY CONNECTS
    // I AM THE PLAYER 1

    // Locally start the game
    while (!game->gameOver())
    {
        game->startRound();
        qDebug() << "game->startRound()";
        // Receive the Deck from Server
        //char test = game->getTCP().receive();
        string deck = game->getTCP().receive();

        //string deck_read = game->getTCP().read();
        //const char * deck_char = deck.c_str();
        qDebug() << "deck \n" << deck.c_str();
        //printf("deck %s\n",deck);
        //return 0
        //qDebug() << "DECK RECEIVED (STRING) : " << deck.c_str();
        //printf("DECK RECEIVED (STRING) : %s \n", deck);
        //printf("DECK RECEIVED (CHAR* c_str) : %s \n", deck_char);
        //cout << "aaa \n";

        // ------ DEBUG ----------------
        // return 0;

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
