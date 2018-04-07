#include "Button.h"
#include "MainWindow.h"

Button::Button(sf::Vector2f position)
{
    this->position = position;
    this->functionPtr = NULL;
}

Button::~Button()
{
}

bool Button::mouseInside()
{
    sf::Vector2i m_position = sf::Mouse::getPosition(*MainWindow::getInstance());
    return (rect.left <= m_position.x && rect.top <= m_position.y
            && rect.left + rect.width >= m_position.x
            && rect.top + rect.height >= m_position.y);
}

void Button::onClick(void (*functionPtr)())
{
    this->functionPtr = functionPtr;
}

void Button::update()
{
    if (mouseInside()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (functionPtr)
                (*functionPtr)();
        }
    }
}
