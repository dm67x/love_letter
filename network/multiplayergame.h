#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include "../core/game.h"
#include <string.h>

class MultiplayerGame : public Game
{
public:
    MultiplayerGame(unsigned int nb);
    void updateServer();
    string serialize();

};

#endif // MULTIPLAYERGAME_H
