#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include "../core/game.h"
#include "src/TCPClient.h"
#include <string.h>

class MultiplayerGame : public Game
{
public:
    MultiplayerGame(unsigned int nb);
    void updateServer();
    string serialize();
    void sig_exit();
    void tcpExit();

    void createServer();
    void joinServer(string ip);

private:
    TCPClient tcp;

};

#endif // MULTIPLAYERGAME_H
