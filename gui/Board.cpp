#include "Board.h"

Board::Board(Core::Game *game, sf::Vector2f position)
{
    this->game = game;
    deck = new Deck(game->getDeck(), position);

    // Players zones
    std::vector<Core::Player *> players = game->getPlayers();
    unsigned int nb_players = players.size();
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
