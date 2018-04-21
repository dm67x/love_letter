#include "Board.h"
#include "MainWindow.h"

Board::Board(Core::Game *game, sf::FloatRect bounds)
    : Object("board")
{
    this->game = game;
    this->bounds = bounds;

    top = left = right = bottom = false;

    sf::Vector2f deck_position;
    deck_position.x = bounds.left + bounds.width / 2.0f;
    deck_position.y = bounds.top + bounds.height / 2.0f;
    deck = new Deck(game->getDeck());
    deck->setPosition(deck_position);
}

Board::~Board()
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        delete *it;
    }

    delete deck;
}

void Board::addPlayer(Core::Player * player, enum ZONE where)
{
    PlayerZone * zone;
    sf::FloatRect zone_bounds;
    sf::FloatRect board_rect = getBounds();

    zone_bounds.top = board_rect.top + (board_rect.height * 3) / 4.0f;
    zone_bounds.left = board_rect.left + board_rect.width / 4.0f;
    zone_bounds.width = board_rect.width / 2.0f;
    zone_bounds.height = board_rect.height / 4.0f;

    zone = new PlayerZone(player, zone_bounds);

    switch (where) {
    case BOTTOM:
        break;

    case TOP:
        zone->rotate(180.0f);
        zone->setPosition(board_rect.left + board_rect.width / 2.0f,
                          board_rect.top + zone_bounds.height / 2.0f);
        break;

    case LEFT:
        zone->rotate(90.0f);
        zone->setPosition(board_rect.left + zone_bounds.height / 2.0f,
                          board_rect.top + board_rect.height / 2.0f);
        break;

    case RIGHT:
        zone->rotate(270.0f);
        zone->setPosition(board_rect.left + board_rect.width - zone_bounds.height / 2.0f,
                          board_rect.top + board_rect.height / 2.0f);
        break;
    }

    zones.push_back(zone);
}

void Board::nextTurn()
{
    // Rotate board
    /*transform.rotate(180.0f, sf::Vector2f(board_rect.left + board_rect.width / 2.0f,
                                         board_rect.top + board_rect.height / 2.0f));*/
}

void Board::update(float dt)
{
    for (unsigned int i = 0; i < zones.size(); i++) {
        zones[i]->update(dt);
        zones[i]->getHand()->mask();
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*deck);
    for (unsigned int i = 0; i < zones.size(); i++)
        target.draw(*zones[i], states);
}
