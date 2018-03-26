#include "multiplayergame.h"
#include <iostream>
#include <signal.h>
#include "TCPClient.h"

MultiplayerGame::MultiplayerGame() : Game(nb)
{

}

// SIGINT HANDLER
void sig_exit(int s)
{
    tcp.exit();
    exit(0);
}

// Serialize infos for update
string serialize(){
    string s = "nbp:"+nb_players;
    // Add player's cards
    for(int i = 0; i < nb_players; i++){
        for(int j = 0; j < 2; j++){
            s += ";"+players[i].getCard(j).getName().at(0);
        }
        s += "!";
    }
    return s;
}

// Send my infos to the Server
void MultiplayerGame::updateServer(){
    TCPClient tcp;

    signal(SIGINT, sig_exit);

    tcp.setup("127.0.0.1",8888);

    srand(time(NULL));
    tcp.Send(to_string(rand()%25000));
    string rec = tcp.receive();
    if( rec != "" )
    {
        cout << "Server Response:" << rec << endl;
    }
    sleep(1);
}

// 1. Server creates new game(nb_players)
// 2. Shuffle the Deck, give cards to players
// 3. Broadcast info

// OR : Client 1 do this, so Server only stocks informations +++
