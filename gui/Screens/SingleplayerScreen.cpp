#include "SingleplayerScreen.h"
#include "SinglePlayerMenuScreen.h"
#include "SingleplayerModeChoiceScreen.h"
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
    Screen::loadContent();

    int nb_players;

    ScreenManager * instance = ScreenManager::getInstance();

    if(instance->getPrevious()->getName() == "singleplayermenu")
        nb_players = SingleplayermenuScreen::players_number;
    else if(instance->getPrevious()->getName() == "singleplayermodechoice") {
        nb_players = SingleplayerModeChoiceScreen::players_number;
    }
    else
        nb_players = 2;

    // Init game
    game = new Core::Game(nb_players);
    ia = new IA::IA_intel(game);
    game->startRound();

    // Board
    sf::Vector2u size = getSize();
    board = new Board(game, sf::FloatRect(0, 0, size.x, size.y));
}

void SingleplayerScreen::input(sf::Event evt)
{
    board->input(evt);

    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::T
            && game->getDeck()->getCards().size() > 0)
        board->nextTurn();
}

void SingleplayerScreen::update(float dt)
{
    game->update();
    board->update(dt);

    if (game->roundOver())
        // set winner screen and restart round

    if (game->gameOver())
        ScreenManager::getInstance()->switchTo("menu");
}

void SingleplayerScreen::draw(sf::RenderWindow &window)
{
    window.clear();
    window.draw(*board);
}
