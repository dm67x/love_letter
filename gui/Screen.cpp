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

void Screen::loadContent()
{
    content_loaded = true;
}

void Screen::input(sf::Event evt)
{
    (void)evt;
}

void Screen::update(float dt)
{
    (void)dt;
}
