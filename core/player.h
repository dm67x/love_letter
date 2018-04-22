#ifndef PLAYER_CORE_H
#define PLAYER_CORE_H

#include <list>
#include <string.h>
#include "card.h"

namespace Core {

class Player
{

private:
    std::string name;
    std::list<Card *> played_cards; // played cards list
    Card * hand[2]; // cards in hand (max 2 cards)
    bool dead;
    bool shield; // Handmaid effect activate or not
    unsigned short points; // points

public:
    Player(string name);
    ~Player();

    // GET
    inline string getName() const { return name; }
    inline std::list<Card *> getPlayedCards() const { return played_cards; }
    inline unsigned short getPoints() const { return points; }
    inline bool hasShield() const { return shield; }
    inline bool isDead() const { return dead; }
    inline Card * getCard(int i = 0) const { return hand[i] ? hand[i] : NULL; }

    // OTHERS
    void kill(); // dead = true
    void reincarnate(); // dead = false
    Card * pickCard(); // pick card from Deck
    void switchHand(Player & p); // switch hand with player "p"
    void setCard(Card * c); // set hand card
    void givePoint(); // give one point to player
    void activateShield(); // shield = true
    void deactivateShield(); // shield = false
    // discard (or play) the card with index "index"
    // if index = -1 then don't activate effect of discarded card
    void discard(int index);
    void discardWithoutEffect(int index);
    void clear(); // reinitialize (not points)
    void reset(); // reinit all (including points)
    int hasCard(string card_name);

    // FOR MULTIPLAYER GAME PURPOSE
    void pickCard_manual(char c);

};

}

#endif // PLAYER_CORE_H
