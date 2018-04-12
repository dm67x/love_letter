#include "Board.h"

Board::Board(Core::Game *game, sf::Vector2f position)
{
    this->game = game;
    deck = new Deck(game->getDeck(), position);

    // Players zones
    std::vector<Core::Player *> players = game->getPlayers();
    Core::Player * current = game->getCurrentPlayer();

    int i = 0;
    while (players.size() > 0) {
        if (current == players.back()) {
            zones.push_back(new PlayerZone(players.back(), BOTTOM));
        } else {
            switch (i) {
            case 0:
                zones.push_back(new PlayerZone(players.back(), TOP));
                break;

            case 1:
                zones.push_back(new PlayerZone(players.back(), LEFT));
                break;

            case 2:
                zones.push_back(new PlayerZone(players.back(), RIGHT));
                break;

            default: break;
            }

            i++;
        }
        players.pop_back();
    }
}

Board::~Board()
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        delete *it;
    }

    delete deck;
}

void Board::clear()
{

}

void Board::rotate()
{

}

void Board::update(float dt)
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        (*it)->update(dt);
    }
}

void Board::draw(sf::RenderWindow &window)
{
    deck->draw(window);
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        (*it)->draw(window);
    }
}
