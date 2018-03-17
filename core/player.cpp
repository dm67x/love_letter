#include "player.h"

Player::Player(string name){
        this->name = name;
        dead = false;
        points = 0;
        isProtected = false;
}

string Player::getName(){
    return name;
}

list<Card *> Player::getCards(){
    return cards;
}

int Player::getPoints(){
    return points;
}

bool Player::isDead(){
    return this->dead;
}

bool Player::hasProtection(){
    return isProtected;
}

//checks if player has card c in hand
bool Player::hasCard(Card &c){
    bool res;
    if (cards.empty()){
        res=false;
    }else{
        if(cards.front()->isTheSameCardAs(c)  ||
           cards.back()->isTheSameCardAs(c)){
               res=true;
        }
    }
    return res;
}


void Player::setDead(bool value){
    dead=value;
}

void Player::addPoint(){
    points++;
}

//add the newly picked card last in the list
void Player::pickCard(Card &c){
    cards.push_back(&c);
}

//switch cards with another player p
void Player::switchHand(Player &p){
    cards.swap(p.getCards());
}


void Player::setProtection(bool value){
    isProtected=value;
}


//discard the only card the plays has in their hands
//normally used to implement the effect
//of the Prince just before picking a new card
void Player::discard(){
    cards.pop_front();
}

//play a chosen card
//precond: c is in the list of cards and is chosen by the player
//(determined through the GUI)
void Player::play(Card &c){
    if(cards.front()->isTheSameCardAs(c))
        cards.pop_front();
    else cards.pop_back();
}

//returns the current and only card that the player has in his hand
//can be used to implement the effect of the Priest
//the player p to whom we show cards we're gonna get him through the GUI
Card * Player::showHand(){
    return cards.front();
}



