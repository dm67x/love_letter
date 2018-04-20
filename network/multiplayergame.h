#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include "../core/game.h"
#include "src/TCPClient.h"
#include <string.h>

class MultiplayerGame : public Core::Game
{
public:
    MultiplayerGame(unsigned int nb);
    void updateServer();
    void sig_exit();
    void tcpExit();

    void createServer();
    int joinServer(string ip);
    TCPClient getTCP();
    int receiveServer();

private:
    TCPClient tcp;

};

#endif // MULTIPLAYERGAME_H
