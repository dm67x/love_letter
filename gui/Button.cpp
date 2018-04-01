#include "Button.h"
#include "MainWindow.h"

Button::Button(std::string text, sf::Vector2f position)
{
    this->text = text;
    this->functionPtr = NULL;
    this->position = position;

    // Texture
    texture.loadFromFile("data/button.png");
    hover_texture.loadFromFile("data/button_hover.png");
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(position);

    // Font & text
    font.loadFromFile("data/Airplanes in the Night Sky.ttf");

    d_text.setFont(font);
    d_text.setString(text);
    d_text.setCharacterSize(40);
    d_text.setFillColor(sf::Color::Black);
    d_text.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect = d_text.getLocalBounds();
    d_text.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2);
    d_text.setPosition(position);
}

Button::~Button()
{
}

void Button::onClick(void (*functionPtr)())
{
    this->functionPtr = functionPtr;
}

void Button::update()
{
    sf::Vector2i m_position = sf::Mouse::getPosition(*MainWindow::getInstance());
    sf::Vector2f position = sprite.getPosition();
    sf::Vector2u size = texture.getSize();

    if (position.x - size.x / 2 <= m_position.x && position.y - size.y / 2 <= m_position.y
            && position.x + size.x / 2 >= m_position.x && position.y + size.y / 2 >= m_position.y) {
        // Change texture (for hover)
        sprite.setTexture(hover_texture);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (functionPtr)
                (*functionPtr)();
        }
    } else {
        sprite.setTexture(texture);
    }
}

void Button::draw(sf::RenderWindow & window)
{
    window.draw(sprite);
    window.draw(d_text);
}
