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
    /* USELESS
    // GETTING MY OWN IP
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

    // addressBuffer STORES THE ADRESS (either IPv4 or IPv6)
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
        } else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
        }
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);

    // Call ./server with my IP ------------ Do we need to specify the IP Address ?
    string line = "./server/server ";
    line += addressBuffer;
    system(line.c_str());
    */

    std::system("../../love_letter/network/server/server");
    //system("pause");

}

void MultiplayerGame::joinServer(string ip){

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
void MultiplayerGame::sig_exit()
{
    tcp.exit();
    exit(0);
}


// 1. Server creates new game(nb_players)
// 2. Shuffle the Deck, give cards to players
// 3. Broadcast info

// OR : Client 1 do this, so Server only stocks informations +++
