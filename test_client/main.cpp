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

    string played_cards = ""; //receive/receive played cards

    int myNumber = game->joinServer("127.0.0.1"); //1 //2
    qDebug() << "myNumber : " << myNumber;

    // OTHER GUY CONNECTS
    // I AM THE PLAYER 1

    // Locally start the game
    while (!game->gameOver())
    {
        game->startRound();
        qDebug() << "game->startRound()";
        // Receive the Deck from Server
        string deck = game->getTCP().receive();
        qDebug() << "deck RECEIVED \n" << deck.c_str();

        string first_cards = deck.substr(deck.length() - 2); //last 2 letters

        // BUILD DECK
        game->setDeck(deck);
        game->setFirstCards(first_cards);

        qDebug() << "first_cards " << first_cards.c_str() << "\n";

        while (!game->roundOver())
        {
            // If it's not my turn, I wait for server to tell me smth
            if(game->getCurrentPlayerIndex() != myNumber){
                played_cards = game->getTCP().receive();
                qDebug() << "played_cards " << played_cards.c_str() << "\n";

                if(played_cards.length() < 1){
                    // MUST THROW AN ERROR
                }
                // Reproduce on my local game what happened on the others

                qDebug() << "Core::Player * p = game->startTurn(); \n";
                Core::Player * p = game->startTurn();
                p->pickCard();

                // Show cards to play
                string c1 = p->getCard()->getName();
                string c2 = p->getCard(1)->getName();
                qDebug() << "c1 : " << c1.c_str() << "\n";
                qDebug() << "c2 : " << c2.c_str() << "\n";


                qDebug() << "p->pickCard();";
                p->pickCard();

                // Played Card
                if(played_cards.length() == 1){
                    qDebug() << "played_cards.length() == 1 \n";
                    qDebug() << "p->discard(atoi(played_cards.c_str())); \n";
                    p->discard(atoi(played_cards.c_str()));
                }


                qDebug() << "HEY \n";

                // Played Card + Target
                if(played_cards.length() == 2){
                    qDebug() << "played_cards.length() == 2 \n";
                    qDebug() << "pickTarget(played_cards.at(1)) \n";
                    game->pickTarget(played_cards.at(1));
                    qDebug() << "p->discard(int(played_cards.at(0))) \n";
                    p->discard(int(played_cards.at(0)));
                }

                // Played Card + Target + Guessed Card
                if(played_cards.length() == 3){
                    qDebug() << "played_cards.length() == 3 \n";
                    qDebug() << "pickTarget(played_cards.at(1)) \n";
                    game->pickTarget(played_cards.at(1));
                    qDebug() << "guessCard(played_cards.substr(2)) \n";
                    game->guessCard(played_cards.substr(2));
                    qDebug() << "p->discard(int(played_cards.at(0))) \n";
                    p->discard(int(played_cards.at(0)));
                }


                qDebug() << "sleep(50) \n";
                sleep(50);

            // It is my turn
            }else{
                printf("IT IS MY TURN \n");
                played_cards = ""; //use this to send server infos

                Core::Player * p = game->startTurn();
                p->pickCard();

                // Show cards to play
                std::cout << "0: " << p->getCard()->getName() << std::endl;
                std::cout << "1: " << p->getCard(1)->getName() << std::endl;

                // Select card to play
                //std::cout << "Which card to play ?" << std::endl;
                //int play_card;
                //std::cin >> play_card;


                // MANUALLY CHOOSE FIRST CARD (cin not working under QT console)
                played_cards += "0"; // send to server


                if (p->getCard()->getName() == "Guard") {

                    //std::cout << "Choose a target ?" << std::endl;
                    //int target;
                    //std::cin >> target;


                    played_cards += "1"; // send to server


                    //std::cout << "Guess a card ?" << std::endl;
                    //std::string card;
                    //std::cin >> card;


                    played_cards += "0"; // send to server

                    game->pickTarget(1);
                    game->guessCard("Baron");
                }

                if(p->getCard()->getName() == "Prince" || p->getCard()->getName() == "Priest" || p->getCard()->getName() == "King"){
                    game->pickTarget(1);
                    played_cards += "1"; // send to server
                }

                sleep(1);
                // SEND INFO TO SERVER
                printf("Sending this : %s : To server \n", played_cards);
                game->getTCP().Send(played_cards);

                qDebug() << "sleep(50) \n";
                sleep(50);

                p->discard(0);

                game->update();
            }

        }
    }


}
