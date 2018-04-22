#include "game.h"

namespace Core {

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
            players.push_back(new Player("player " + std::to_string(i)));
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
    deck->removeCard(); // remove one card from deck

    if (nb_players == 2) {
        // remove three more cards if two players in game
        deck->removeCard();
        deck->removeCard();
        deck->removeCard();
    } else {
        // remove one more card
        deck->removeCard();
    }

    // init players and give them a card
    for (std::vector<Player *>::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->clear();
        (*i)->pickCard();
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
    Player * p = players[current_player];
    while (p->isDead())
    {
        current_player = (current_player + 1) % nb_players;
        p = players[current_player];
    }

    current_player = (current_player + 1) % nb_players;
    if(p->hasShield())
        p->deactivateShield();
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
    nb_dead = 0;
    for (unsigned int i = 0; i < players.size(); i++) {
        if (players[i]->isDead())
            nb_dead++;
    }

    if (nb_dead == nb_players - 1 || deck->getCards().size() == 0)
    {
        // End round
        std::vector<Player *> alives;
        Player * winner;

        round_end = true;
        for (unsigned int i = 0; i < players.size(); i++) {
            if (!players[i]->isDead()) {
                alives.push_back(players[i]);
            }
        }

        if (alives.size() > 1) {
            for (unsigned int i = 0; i < alives.size() - 1; i++)
            {
                if (alives[i]->getCard()->getValue() < alives[i+1]->getCard()->getValue()) {
                    alives[i]->kill();
                    winner = alives[i+1];
                }
                else if (alives[i]->getCard()->getValue() == alives[i+1]->getCard()->getValue()) {
                    int sum_1 = 0, sum_2 = 0;
                    // Sum of played cards 1
                    for (std::list<Card *>::iterator card_it = alives[i]->getPlayedCards().begin();
                         card_it != alives[i]->getPlayedCards().end(); card_it++) {
                        sum_1 += (*card_it)->getValue();
                    }

                    // Sum of played cards 2
                    for (std::list<Card *>::iterator card_it = alives[i+1]->getPlayedCards().begin();
                         card_it != alives[i+1]->getPlayedCards().end(); card_it++) {
                        sum_2 += (*card_it)->getValue();
                    }

                    if (sum_1 < sum_2) {
                        alives[i]->kill();
                        winner = alives[i+1];
                    } else {
                        alives[i+1]->kill();
                        winner = alives[i];
                    }
                }
                else {
                    alives[i+1]->kill();
                    winner = alives[i];
                }
            }
        } else {
            // One winner
            winner = alives[0];
        }

        winner->givePoint();
        for (unsigned int i = 0; i < players.size(); i++) {
            if (players[i] == winner)
                current_winner = i;
        }

        if (winner->getPoints() == max_points) {
            game_end = true;
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

// Return current player
int Game::getCurrentPlayerIndex(){
    return current_player;
}

void Game::setDeck(string d){
    deck->buildDeck(d);
}

void Game::setFirstCards(string first_cards){
    for (std::string::size_type i = 0; i < first_cards.size(); i++)
    {
        players[i]->clear();
        players[i]->pickCard_manual(first_cards[i]);
    }
}


}
