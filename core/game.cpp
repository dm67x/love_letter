#include "game.h"
#include "cards/all.h"

#include <algorithm>
#include <vector>

using namespace std;

// Shuffle the deck
void listShuffle( list<Card*> &L ){
   vector<Card*> V( L.begin(), L.end() );
   shuffle( V.begin(), V.end(), mt19937{ random_device{}() } );
   L.assign( V.begin(), V.end() );
}

// Start new Game with nb_players
Game::Game(int nb_players){
    if(nb_players < 2 || nb_players > 4){
        // TODO generate error
    }
    this->nb_players = nb_players;
    current_player = 0;
    nb_dead = 0;
    nb_cards = 16;

    //action
    action = Action::getInstance();
}

// Init player tabs and maxpoints
// Init cards and randomize the deck
void Game::start(){
    // PLAYERS
    for(int i = 0; i < nb_players; i++){
        players[i] = new Player(""+i);
    }
    if(nb_players == 2){
        max_points = 7;
    }else if(nb_players == 3){
        max_points = 5;
    }else{
        max_points = 4;
    }

    // CARDS
    // Initialize Classic Deck
    cards = {new Guard(), new Guard(), new Guard(),
                new Guard(), new Guard(), new Priest(),
                new Priest(), new Baron(), new Baron(),
                new Handmaid(), new Handmaid(), new Prince(),
                new Prince(), new King(), new Countess(),
                new Princess()};

    // Randomize
    listShuffle(cards);

    //Drop cards if needed
    if(nb_players == 2){
        nb_cards -= 3;
        for(int i = 0; i < 3; i++){
            cards.pop_back();
        }
    }
}

// Start a round
void Game::startRound(){
    // Each player pick one card
    for(int i = 0; i < nb_players; i++){
        if(!players[i]->isDead()){ //Don't give a card to someone who's dead
            giveCard(players[i]);
        }
    }
}

// Someone plays
// If he had the handmaid effect, remove it.
void Game::startTurn(Card * c){ //The card is given by the IHM
    // Check if current player is dead
    if(!players[current_player]->isDead()){
        // Remove Handmaid effect
        if(players[current_player]->hasProtection()){
            players[current_player]->setProtection(false);
        }
        // Start turn
        players[current_player]->play(c);
    }

    // Set next player turn
    current_player ++;
    current_player %= nb_players;
}

// For cards that need to pick an other player as Target
// Set action.target
void Game::pickTarget(Player * p){
    action->target = p;
}

// Specific for Guard : try to guess an other player's card
// Set action.c1
void Game::guessCard(Card * c){
    action->c1 = c;
}

// Update game information
// Check if round/game is over
void Game::update(){
    for(int i = 0; i < nb_players; i++){
        if(players[i]->isDead()){
            nb_dead++;
        }
    }
    // Round is over
    if(nb_dead = nb_players - 1 || nb_cards == 0){
        givePoint();
    }

    checkEnd();
}

// Check whether or not game is over
// => someone reached max point
void Game::checkEnd(){
    for(int i = 0; i < nb_players; i++){
        if(players[i]->getPoints() == max_points){
            end = true;
        }
    }
}

// Give point to last player alive
// Or the one who has the greatest card
void Game::givePoint(){
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

}

// Give card to Player p
void Game::giveCard(Player * p){
    p->pickCard(cards.back());
    cards.pop_back();
    nb_cards--;
}

// True if game is over
bool Game::isOver(){
    return end;
}

// Return current player
Player * Game::getCurrentPlayer(){
    return players[current_player];
}
