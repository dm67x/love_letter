#include "Player.h"

Player::Player()
{

}

Player::Player(std::list<Card> cards, sf::Vector2f handPos)
{
    handPosition = handPos;
    hand = cards;
    // TODO: position card(s) with handPosition
}

Player::~Player()
{

}

void draw()
{
    foreach (Card c, hand)
    {
        //TODO: Add something like "c.draw();" to Card
    }
}

void moveHand(sf::Vector2f dPosition)
{
    foreach (Card c, hand)
    {
        c.move(dPosition);
    }
}
