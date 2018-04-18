#include "game.h"


// Start new Game with nb_players
Game::Game(unsigned int nb_players){

    action = Action::getInstance();
    deck = Deck::getInstance();

    //init class fields
    this->nb_players = nb_players;
    current_player = 0;
    current_winner = -1;
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
    deck->clear();
    deck->pickCard(); //

    if (nb_players == 2) {
        //
        deck->pickCard();
        deck->pickCard();
        deck->pickCard();
    } else {
        deck->pickCard();
    }

    // init players and give them a card
    for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->setDead(false);
        (*i)->setProtection(false);
        (*i)->pickCard(*deck);
    }

    nb_dead = 0;
    // the winner from the last round starts the new round
    if (current_winner != -1)
        current_player = current_winner;
    // if first round, the player 0 starts the round
    else current_player = 0;
    round_end = false;
}

unsigned int Game::getMaxPoints(){
    return max_points;
}

void Game::setCurrentWinner(int index){
    current_winner = index;
}

int Game::getCurrentWinner(){
    return current_winner;
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
    action->deck = deck;
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
    if (nb_dead == nb_players - 1 || deck->count() == 0)
    {
        Player * winner = NULL;
        round_end = true;
        for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++)
        {
            // init winner to current player index
            if (!winner) winner = (*i);
            // if winner is initialized
            else {
                // if "i" has bigger card value than "winner", "i" wins the game
                if (winner->getCard()->getValue() < (*i)->getCard()->getValue()) {
                    winner->setDead(true);
                    winner = (*i);
                }
                // if it's a tie
                else if (winner->getCard()->getValue() == (*i)->getCard()->getValue()) {
                    int sum_w = 0, sum_i = 0;
                    // Sum of played cards of "winner"
                    while (winner->getPlayedCards().size() != 0) {
                        Card * c = winner->getPlayedCards().top();
                        sum_w += c->getValue();
                        winner->getPlayedCards().pop();
                    }

                    // Sum of played cards of "i"
                    while ((*i)->getPlayedCards().size() != 0) {
                        Card * c = (*i)->getPlayedCards().top();
                        sum_i += c->getValue();
                        (*i)->getPlayedCards().pop();
                    }

                    if (sum_w < sum_i) {
                        winner->setDead(true);
                        winner = *i;
                    }
                }
            }

            (*i)->emptyCardsList();

            if (!(*i)->isDead()) {
                (*i)->givePoint();
                if ((*i)->getPoints() == max_points){
                    current_winner = i - players.begin();
                    game_end = true;
                }
            }
        }
    }
}

// check if game is over
bool Game::gameOver(){
    return game_end;
}

// Return current player
Player * Game::getCurrentPlayer(){
    return players[current_player];
}
