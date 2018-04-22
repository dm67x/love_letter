#include "player.h"
#include "deck.h"
#include "cards/all.h"
#include <QDebug>

namespace Core {

Player::Player(string name)
{
    this->name = name;
    dead = shield = false;
    points = 0;
    hand[0] = NULL;
    hand[1] = NULL;
}

Player::~Player()
{
    if (hand[0])
        delete hand[0];
    if (hand[1])
        delete hand[1];
    for (std::list<Card *>::iterator it = played_cards.begin(); it != played_cards.end(); it++)
        delete (*it);
}

void Player::kill()
{
    dead = true;
    // discard last card in hand because "i'm dead"
    if (hand[0])
        discard();
}

void Player::reincarnate()
{
    dead = false;
}

Card * Player::pickCard()
{
    Card * picked_card = Deck::getInstance()->pickCard();
    if (hand[0] == NULL)
        hand[0] = picked_card;
    else
        hand[1] = picked_card;

    // If countess in hand
    if ((hand[0] && hand[0]->getValue() == 7) || (hand[1] && hand[1]->getValue() == 7)) {
        if (hand[0] && (hand[0]->getValue() == 6 || hand[0]->getValue() == 5)) {
            hand[0]->setActive(false);
        } else if (hand[1] && (hand[1]->getValue() == 6 || hand[1]->getValue() == 5)) {
            hand[1]->setActive(false);
        }
    } else {
        if (hand[0])
            hand[0]->setActive(true);
        if (hand[1])
            hand[1]->setActive(true);
    }

    return picked_card;
}

void Player::switchHand(Player & p)
{
    if (!p.isDead() && !isDead()) {
        Card * my_card = hand[0];
        hand[0] = p.getCard();
        p.setCard(my_card);
    }
}

void Player::setCard(Card * c)
{
    hand[0] = c;
}

void Player::givePoint()
{
    points++;
}

void Player::activateShield()
{
    shield = true;
}

void Player::deactivateShield()
{
    shield = false;
}

void Player::discard(int index)
{
    if (index == -1 && hand[0] != NULL) {
        // Don't active effect of card
        played_cards.push_back(hand[0]);
        hand[0] = NULL;
    } else if (index >= 0 && hand[index] != NULL) {
        Card * selected = hand[index];
        played_cards.push_back(selected);
        hand[index] = NULL;
        // Change position of card in position 1 to 0
        if (index == 0 && hand[1] != NULL) {
            hand[0] = hand[1];
            hand[1] = NULL;
        }
        selected->activeEffect();
    }
}
// For multiplayer games
// Manually give a card to a client
void Player::pickCard_manual(char c){
    switch (c) {
    case 'G':
        hand[0] = new Guard();
        break;
    case 'P':
        hand[0] = new Priest();
        break;
    case 'B':
        hand[0] = new Baron();
        break;
    case 'H':
        hand[0] = new Handmaid();
        break;
    case 'Y':
        hand[0] = new Prince();
        break;
    case 'K':
        hand[0] = new King();
        break;
    case 'C':
        hand[0] = new Countess();
        break;
    case 'Z':
        hand[0] = new Princess();
        break;
    default:
        break;
    }
}

void Player::clear()
{
    hand[0] = hand[1] = NULL;
    played_cards.clear();
    dead = shield = false;
}

void Player::reset() {
    clear();
    points = 0;
}

int Player::hasCard(string card_name){
    int index;
    if(hand[0]->getName() == card_name)
        index = 0;
    else if(hand[1]->getName() == card_name)
        index = 1;
    else index = -1;
    return index;
}

}

