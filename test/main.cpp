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
#include <QtDebug>
#include "test.h"

using namespace std;

int main()
{
    unsigned int nb = 2;
    MultiplayerGame * game = new MultiplayerGame(nb);

    string rec = ""; //received string from servers
    string played_cards = ""; //receive/send played cards

    // I will be the player 1
    int myNumber = 0;

    char f = 'x';

    string deck = ""; // to send current deck
    string card = ""; // stores current card name

    // Host server - COMMENTED FOR TEST PURPOSE - TO UNCOMMENT
        //game->createServer();

    // Init connection
    //TCPClient * tcp = new TCPClient();

    // Connect localhost cause we host the server
    int s = game->joinServer("127.0.0.1");


    // Locally start the game
    while (!game->gameOver())
    {
        game->startRound();


        // Build string to send to server
        Core::Deck * d = game->getDeck();
        std::list<Core::Card *> cards = d->getCards();
        // STORES LIST CONTENT INTO ARRAY
        Core::Card * arr[cards.size()];
        copy(cards.begin(), cards.end(), arr);

        // add first letter of each card
            // priest = p; prince = y ; princess = z ;
        for(unsigned int i = 0; i < cards.size(); i++){
            card = arr[i]->getName();

            if(card.compare("Prince") == 0){ //if current card is Prince
                f = 'Y';
            }else if(card.compare("Princess") == 0){ //or Princess
                f = 'Z';
            }else{
                f = card.at(0);
            }

            deck += f;
        }

        // Also add first cards given to players
        vector<Core::Player *> players = game->getPlayers();
        for(unsigned int i = 0; i < nb; i++){
            card = players[i]->getCard()->getName();
            if(card.compare("Prince") == 0){ //if current card is Prince
                deck += 'Y';
            }else if(card.compare("Princess") == 0){ //or Princess
                deck += 'Z';
            }else{
                deck += card.at(0);
            }
        }


        //WAIT FOR SERVER TO TELL US WE CAN START
        rec = game->getTCP().receive();
        int r = atoi(rec.c_str());
        printf("%d player on Server \n",r);

        if(r == 0){
            printf("Personne, cant start \n");
        }

        // Send Deck to server
        printf("Sending Deck to server ..\n");
        sleep(1);
        game->getTCP().Send(deck);

        // Server confirms Deck has been broadcasted
        //string res = game->getTCP().receive();

        //return 0;

        while (!game->roundOver())
        {
            // If it's not my turn, I wait for server to tell me smth
            if(game->getCurrentPlayerIndex() != myNumber){
                qDebug() << "NOT MY TURN \n";

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

                // Played Card + Target
                if(played_cards.length() == 2){
                    qDebug() << "played_cards.length() == 2 \n";
                    qDebug() << "pickTarget(played_cards.at(1)) : " << played_cards.at(1) << "\n";
                    game->pickTarget(played_cards.at(1));
                }

                // Played Card + Target + Guessed Card
                if(played_cards.length() == 3){
                    qDebug() << "played_cards.length() == 3 \n";
                    qDebug() << "pickTarget(played_cards.at(1)) :  " << played_cards.at(1) << "\n";
                    game->pickTarget(played_cards.at(1));
                    qDebug() << "guessCard(played_cards.substr(2)) : " << played_cards.substr(2).c_str() << "\n";
                    game->guessCard(played_cards.substr(2));
                }


                qDebug() << "p->discard(int(played_cards.at(0)))" << played_cards.at(0) << "\n";

                int card_to_play = played_cards.at(0) - '0';
                p->discard(card_to_play);


                qDebug() << "sleep(50) \n";

            // It is my turn
            }else{
                qDebug() << "CURRENT INDEX PLAYER " << game->getCurrentPlayerIndex() << "\n";

                qDebug("ITS MY TURN \n");
                rec = ""; //use this to send server infos

                Core::Player * p = game->startTurn();
                p->pickCard();

                // Show cards to play
                std::cout << "0: " << p->getCard()->getName() << std::endl;
                std::cout << "1: " << p->getCard(1)->getName() << std::endl;

                // MANUALLY CHOOSE FIRST CARD
                rec += "0"; // send to server

                if (p->getCard()->getName() == "Guard") {

                    // target = 1
                    rec += "1"; // send to server

                    // card we guess = Baron
                    rec += "Baron"; // send to server

                    game->pickTarget(1);
                    game->guessCard("Baron");
                }

                if(p->getCard()->getName() == "Prince" || p->getCard()->getName() == "Priest"
                        || p->getCard()->getName() == "King" || p->getCard()->getName() == "Baron"){
                    game->pickTarget(1);
                    rec += "1"; // send to server
                }

                sleep(1);
                // SEND INFO TO SERVER
                qDebug() << "sending this to server" << rec.c_str() << "\n";
                game->getTCP().Send(rec);

                //qDebug() << "sleep(50) \n";
                //sleep(50);

                p->discard(0);

                game->update();

            }
        }
    }
}
