#include "DialogBox.h"

#include <iostream>

DialogBox::DialogBox(std::string title_text, sf::Vector2f size)
    : Object("dialogbox")
{
    setOrigin(size * 0.5f);
    setPosition(size * 0.5f);

    is_open = false;
    this->size = size;
}

void DialogBox::open()
{
    is_open = true;
}

void DialogBox::close()
{
    is_open = false;
}

void DialogBox::input(sf::Event evt)
{
}

void DialogBox::update(float dt)
{
}
