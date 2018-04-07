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

void SingleplayerScreen::update(float dt)
{
    (void)dt;
    //game->update();

    if (game->roundOver())
        // set winner screen and restart round

    if (game->gameOver())
        ScreenManager::getInstance()->switchTo("menu");
}

void SingleplayerScreen::draw(sf::RenderWindow &window)
{
    window.clear();
    board->draw(window);
}
