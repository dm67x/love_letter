#include "player.h"
#include "deck.h"

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

    // if picked_card is the countess and you have king or prince in hand you must discard countess
    if (hand[0] && hand[0]->getValue() == 7 && (hand[1]->getValue() == 5 || hand[1]->getValue() == 6))
        discard(0);
    else if (hand[1] && hand[1]->getValue() == 7 && (hand[0]->getValue() == 5 || hand[0]->getValue() == 6))
        discard(1);

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

}
