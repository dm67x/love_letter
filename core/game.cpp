#include "game.h"


// Start new Game with nb_players
Game::Game(unsigned int nb_players){

    action = Action::getInstance();

    //init class fields
    this->nb_players = nb_players;
    current_player = 0;
    nb_dead = 0;
    game_end = false;

    // init max_points
    if(nb_players == 2){
        max_points = 7;
    }else if(nb_players == 3){
        max_points = 5;
    }else{
        max_points = 4;
    }

    // init players
    for (unsigned int i = 1; i <= nb_players; i++)
            players.push_back(new Player("p" + (i + 1)));
}

Game::~Game()
{
    delete deck;
    delete action;

    for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++) {
        delete *i;
    }
}


//start new round
void Game::startRound()
{
    if (deck) delete deck;

    if (nb_players == 2)
        deck = new Deck(13);
    else
        deck = new Deck(16);

    // init players and give them a card
    for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->setDead(false);
        (*i)->setProtection(false);
        (*i)->pickCard(*deck);
    }

    nb_dead = 0;
    current_player = 0;
    round_end = false;
}

unsigned int Game::getMaxPoints(){
    return max_points;
}


Player * Game::startTurn()
{
    nb_dead = 0;
    Player * p = players[current_player];
    while (p->isDead())
    {
        nb_dead++;
        current_player = (current_player + 1) % nb_players;
        p = players[current_player];
    }

    update();

    current_player = (current_player + 1) % nb_players;
    if(p->hasProtection())
        p->setProtection(false);
    action->clear();
    action->current = p;
    return p;
}

Deck * Game::getDeck()
{
    return deck;
}


// For cards that need to pick another player as Target
// Set action.target
void Game::pickTarget(int target_index)
{
    action->target = players[target_index];
}


// Specific for Guard : try to guess an other player's card
// Set action.c1
void Game::guessCard(string name)
{
    action->guess = name;
}

//check if the round is over
bool Game::roundOver()
{
    return round_end;
}


// Update game information
// Check if round/game is over
void Game::update()
{
    if (nb_dead == nb_players - 1)
    {
        round_end = true;
        for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++)
        {
            if (!(*i)->isDead()) {
                (*i)->givePoint();
                if ((*i)->getPoints() == max_points)
                    game_end = true;
            }
        }
    }
}


// TODO REMOVE -> keep it until proven unuseful
// Give point to last player alive
// Or the one who has the greatest card
/*void Game::givePoint(){
    int val = 0;
    // No more cards to pick
    if(nb_cards == 0){
        for(int i = 0; i < nb_players; i++){
            if(players[i]->showHand()->getValue() > val){
                val = players[i]->showHand()->getValue();
            }else{
                players[i]->setDead(true);
            }
        }
    }

    // Give point to the only player alive
    for(int i = 0; i < nb_players; i++){
        if(!players[i]->isDead()){
            players[i]->addPoint();
        }
    }

}*/

// check if game is over
bool Game::gameOver(){
    return game_end;
}

// Return current player
Player * Game::getCurrentPlayer(){
    return players[current_player];
}
