#include "game.h"
#include <algorithm>
#include <vector>

using namespace std;

// Shuffle the deck
void listShuffle( list<Card*> &L )
{
   vector<Card*> V( L.begin(), L.end() );
   shuffle( V.begin(), V.end(), mt19937{ random_device{}() } );
   L.assign( V.begin(), V.end() );
}

Game::Game(int nb_players)
{
    if(nb_players < 2 || nb_players > 4){
        // TODO generate error
    }
    this->nb_players = nb_players;
    current_player = 0;
}

// Init player tabs and maxpoints
// Init cards and randomize the deck
void Game::start(){
    // PLAYERS
    players = new Player[nb_players];
    if(nb_players == 2){
        maxPoints = 7;
    }else if(nb_players == 3){
        maxPoints = 5;
    }else{
        maxPoints = 4;
    }

    // CARDS
    nb_cards = 16;
    // Initialize Classic Deck
    // Compiling errors : classes doesnt exist yet
    /*
    cards = {new Guard(), new Guard(), new Guard(),
                new Guard(), new Guard(), new Priest(),
                new Priest(), new Baron(), new Baron(),
                new Handmaid(), new Handmaid(), new Prince(),
                new Prince(), new King(), new Countess(),
                new Princess()};
    */
    cards = {new Card(), new Card(), new Card()};

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
    for(Player p : players){
        giveCard(p);
    }
}

// Someone plays
// If he had the handmaid effect,
void Game::startTurn(Card c){ //The card is given by the IHM

    // Start turn
    players[current_player].play(Card c);

    current_player ++;
    current_player %= nb_players;
}

void Game::pickTarget(){

}

void Game::guessCard(){

}

Player::play(Card c){
    if(guard){
        //call pick target => pick a player
        //call pick card => display all cards, pick one

        c.effect();
        // how do we know the target ?
    }
    // test that the card is in current player's hand
    // TODO

    // Activate card effect

    // Destroy card
}

// Update game information
// Check who dies, who lives
// Check if round/game is over
void Game::update(){

}

// ????
void Game::checkEnd(){

}

// Give point to last player alive
// Or the one who has the greatest card
void Game::givePoint(){

}

// Give card to Player p
void Game::giveCard(Player p){

}
