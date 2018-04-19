#include "Button.h"

Button::Button(sf::Vector2f position)
    : Object("button")
{
    this->position = position;
    this->functionPtr = NULL;
}

Button::~Button()
{
}

bool Button::mouseInside(sf::Vector2i m_position)
{
    return (rect.left <= m_position.x && rect.top <= m_position.y
            && rect.left + rect.width >= m_position.x
            && rect.top + rect.height >= m_position.y);
}

void Button::onClick(void (*functionPtr)())
{
    this->functionPtr = functionPtr;
}

void Button::input(sf::Event evt)
{
    sf::Vector2i mouse_pos = sf::Vector2i(evt.mouseButton.x, evt.mouseButton.y);
    if (mouseInside(mouse_pos) && evt.type == sf::Event::MouseButtonPressed
            && evt.mouseButton.button == sf::Mouse::Left) {
        if (functionPtr)
            (*functionPtr)();
    }
}

void Button::update(float dt)
{
    (void)dt; // remove unused warning
}
