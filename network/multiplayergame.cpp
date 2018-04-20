#include "multiplayergame.h"
#include <iostream>
#include <signal.h>
#include <stdlib.h>

MultiplayerGame::MultiplayerGame(unsigned int nb) : Game(nb)
{
    //updateServer();
}

// Creates server => starts server.out
void MultiplayerGame::createServer(){
    std::system("../../love_letter/network/server/server");
}

int MultiplayerGame::joinServer(string ip){
    tcp.setup(ip,8888);
    string res = tcp.receive();
    return atoi(res.c_str());
}

int MultiplayerGame::receiveServer(){
    string res = tcp.receive();
    return atoi(res.c_str());
}


// Send my infos to the Server
void MultiplayerGame::updateServer(){
    //signal(SIGINT, sig_exit); TODO

    tcp.setup("127.0.0.1",8888);

    string rec = tcp.receive();
    if( rec != "" )
    {
        cout << "Server Response:" << rec << endl;
    }
    sleep(1);
}

TCPClient MultiplayerGame::getTCP(){
    return tcp;
}


// SIGINT HANDLER => TODO
void MultiplayerGame::sig_exit()
{
    tcp.exit();
    exit(0);
}


// 1. Server creates new game(nb_players)
// 2. Shuffle the Deck, give cards to players
// 3. Broadcast info

// OR : Client 1 do this, so Server only stocks informations +++
