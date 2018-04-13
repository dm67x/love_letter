#include "SingleplayerScreen.h"
#include "ScreenManager.h"

SingleplayerScreen::SingleplayerScreen()
    : Screen("singleplayer")
{
    game = NULL;
    board = NULL;
}

SingleplayerScreen::~SingleplayerScreen()
{
    if (game)
        delete game;

    if (board)
        delete board;
}

void SingleplayerScreen::loadContent()
{
    content_loaded = true;

    // Init game
    game = new Core::Game(4);
    game->startRound();

    // Board
    board = new Board(game, sf::Vector2f(getSize().x / 2.0f, getSize().y / 2.0f));
}

void SingleplayerScreen::update(sf::Event evt, float dt)
{
    (void)dt;
    //game->update();
    board->update(dt);

    if (game->roundOver())
        // set winner screen and restart round

    if (game->gameOver())
        ScreenManager::getInstance()->switchTo("menu");

    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::T)
        board->nextTurn();
}

void SingleplayerScreen::draw(sf::RenderWindow &window)
{
    window.clear();
    board->draw(window);
}
