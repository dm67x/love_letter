#include "player.h"
#include "utils.h"


Player::Player(string name){
        this->name = name;
        dead = false;
        points = 0;
        protection = false;
        cards[0] = NULL;
        cards[1] = NULL;
}

string Player::getName(){
    return name;
}

unsigned int Player::getPoints(){
    return points;
}

bool Player::isDead(){
    return this->dead;
}

bool Player::hasProtection(){
    return protection;
}

//checks if player has card c in hand and return position of that card (0 or 1)
//or -1 if card not there
int Player::hasCard(string card_name)
{
    //if cards[0] non null
    if(cards[0] && cards[0]->getName() == card_name)
        return 0;
    else if(cards[1] && cards[1]->getName() == card_name)
        return 1;
    else return -1;
}

void Player::givePoint(){
    points++;
}



void Player::setDead(bool value){
    dead=value;
}



//pick a card from deck
void Player::pickCard(Deck & d)
{
    Card *c = d.pickCard();
    if (!cards[0])
        cards[1] = c;
    else cards[0] = c;
    // if picked card is a countess and if you have King or Prince in hand, you must discard the countess
    if(c->getValue() == 7 && (cards[0]->getValue() == 6 || cards[0]->getValue() == 5 )){
        play(1);
    }
}


//switch cards with another player p
void Player::switchHand(Player &p){
    Utils::myswap(cards[0],p.getCard());
}


void Player::setProtection(bool value){
    protection = value;
}


//discard the only card the player has in his hands
//normally used to implement the effect
//of the Prince just before picking a new card
void Player::discard(){
    played_cards.push(cards[0]);
    cards[0] = NULL;
}

//play a chosen card
//precond: c is in the list of cards and is chosen by the player
//(determined through the GUI)
void Player::play(int index)
{
    cards[index]->activeEffect();
    played_cards.push(cards[index]);
    cards[index] = NULL;
    if (index == 0) {
        cards[0] = cards[1];
        cards[1] = NULL;
    }
}

void Player::emptyCardsList()
{
    played_cards.empty();
    cards[0] = cards[1] = NULL;
}

stack<Card *> Player::getPlayedCards()
{
    return played_cards;
}


//returns the current and only card that the player has in his hand
//can be used to implement the effect of the Priest
//the player p to whom we show cards we're gonna get him through the GUI
Card * Player::getCard(int i){
    return cards[i];
}



