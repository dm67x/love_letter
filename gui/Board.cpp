#include "Board.h"
#include "MainWindow.h"

#include <iostream>

Board::Board(Core::Game *game, sf::FloatRect bounds)
    : Object("board")
{
    this->game = game;
    this->bounds = bounds;

    setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
    setPosition(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);

    sf::Vector2f deck_position;
    deck_position.x = bounds.left + bounds.width / 2.0f;
    deck_position.y = bounds.top + bounds.height / 2.0f;
    deck = new Deck(game->getDeck());
    deck->setPosition(deck_position);

    // Board background
    if (!board_bg_texture.loadFromFile("data/board_royal.jpg")) {
        std::cerr << "cannot load data file" << std::endl;
        exit(1);
    }

    board_bg.setTexture(board_bg_texture);
    board_bg.setPosition(0, 0);
    board_bg.setScale(bounds.width / board_bg_texture.getSize().x,
                      bounds.height / board_bg_texture.getSize().y);
}

Board::~Board()
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        delete *it;
    }

    delete deck;
}

void Board::resetDeck()
{
    deck->refresh();
    for (auto it = zones.begin(); it != zones.end(); it++) {
        (*it)->clear();
    }
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
    if (zones.size() == 2) {
        //rotate(180.0f);
    } else if (zones.size() == 3) {

    } else {
        //rotate(90.0f);
    }
}

void Board::update(float dt)
{
    for (unsigned int i = 0; i < zones.size(); i++) {
        zones[i]->update(dt, getTransform());
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(board_bg, states);
    target.draw(*deck);
    for (unsigned int i = 0; i < zones.size(); i++)
        target.draw(*zones[i], states);
}
