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

        //printf("AVANT LE FOR !\n");


        for(unsigned int i = 0; i < cards.size(); i++){
            card = arr[i]->getName();

            if(card.compare("Prince") == 0){ //if current card is Prince
                f = 'Y';
            }else if(card.compare("Princess") == 0){ //or Princess
                f = 'Z';
            }else{
                f = card.at(0);
            }

            cout << "full card name " << card << " \n";
            //printf("card full name : %s \n", card);
            printf("first letter : %c \n", f);
            deck += f;
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
        game->getTCP().Send(deck);

        //return 0;

        while (!game->roundOver())
        {
            // If it's not my turn, I wait for server to tell me smth
            if(game->getCurrentPlayerIndex() != myNumber){
                rec = game->getTCP().receive();
                printf("just received played cards : %s\n",rec);

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
                printf("IT IS MY TURN \n");
                rec = ""; //use this to send server infos

                Core::Player * p = game->startTurn();
                p->pickCard();

                // Show cards to play
                std::cout << "0: " << p->getCard()->getName() << std::endl;
                std::cout << "1: " << p->getCard(1)->getName() << std::endl;

                // Select card to play
                /*
                std::cout << "Which card to play ?" << std::endl;
                int play_card;
                std::cin >> play_card;
                */

                // MANUALLY CHOOSE FIRST CARD (cin not working under QT console)
                rec += "0"; // send to server


                if (p->getCard()->getName() == "Guard") {
                    /*
                    std::cout << "Choose a target ?" << std::endl;
                    int target;
                    std::cin >> target;
                    */

                    rec += "1"; // send to server

                    /*
                    std::cout << "Guess a card ?" << std::endl;
                    std::string card;
                    std::cin >> card;
                    */

                    rec += "0"; // send to server

                    game->pickTarget(1);
                    game->guessCard("Baron");
                }

                if(p->getCard()->getName() == "Prince" || p->getCard()->getName() == "Priest" || p->getCard()->getName() == "King"){
                    game->pickTarget(1);
                    rec += "1"; // send to server
                }

                // SEND INFO TO SERVER
                printf("Sending this : %s : To server \n", rec);
                game->getTCP().Send(rec);

                p->discard(0);

                game->update();

            }
        }
    }
}

