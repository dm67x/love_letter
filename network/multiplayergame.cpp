#include "multiplayergame.h"
#include <iostream>
#include <signal.h>

MultiplayerGame::MultiplayerGame(unsigned int nb) : Game(nb)
{
    //updateServer();
}

// Serialize infos for update TODO
string MultiplayerGame::serialize(){
    string s = "nbp:"+nb_players;
    // Add player's cards
    for(unsigned int i = 0; i < nb_players; i++){
        for(int j = 0; j < 2; j++){
            s += ";"+players[i]->getCard(j)->getName().at(0);
        }
        s += "!";
    }
    return s;
}

// Send my infos to the Server
void MultiplayerGame::updateServer(){
    //signal(SIGINT, sig_exit); TODO

    tcp.setup("127.0.0.1",8888);

    tcp.Send(serialize());
    string rec = tcp.receive();
    if( rec != "" )
    {
        cout << "Server Response:" << rec << endl;
    }
    sleep(1);
}


// SIGINT HANDLER => TODO
void MultiplayerGame::sig_exit(int s)
{
    tcp.exit();
    exit(0);
}


// 1. Server creates new game(nb_players)
// 2. Shuffle the Deck, give cards to players
// 3. Broadcast info

// OR : Client 1 do this, so Server only stocks informations +++
