#include "Screen.h"
#include "MainWindow.h"

Screen::Screen(std::string name)
{
    screen_name = name;
    content_loaded = false;
}

Screen::~Screen()
{
}

sf::Vector2u Screen::getSize()
{
    return MainWindow::getInstance()->getWindow()->getSize();
}

int Screen::playing_card(int index, Core::Card *card)
{
    (void)index;
    (void)card;
    return -1;
}

void Screen::loadContent()
{
    content_loaded = true;
}

void Screen::unloadContent()
{
    content_loaded = false;
}

void Screen::input(sf::Event evt)
{
    (void)evt;
}

void Screen::update(float dt)
{
    (void)dt;
}
