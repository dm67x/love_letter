#include "TextArea.h"
#include <sstream>
#include <string>

TextArea::TextArea(sf::Vector2f position)
    : Button(position)
{
    n_color = sf::Color(226, 26, 57);
    h_color = sf::Color(0, 128, 128);

    // Font & text
    font.loadFromFile("data/Another day in Paradise.ttf");

    this->text.setFont(font);
    this->text.setString("");
    this->text.setCharacterSize(25);
    this->text.setFillColor(n_color);
    this->text.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect = this->text.getLocalBounds();
    this->text.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2);
    this->text.setPosition(position);

    rect = this->text.getGlobalBounds();

    // true de base normalement
    hasFocus = true;
}

TextArea::~TextArea()
{

}

// marche pas
void TextArea::update(sf::Event evt)
{
    Button::update();

    if (hasFocus) {
        // TODO: bords bleu
        switch (evt.type)
        {
            case sf::Event::TextEntered:
            {
                printf("TEST");
                char c = static_cast<char>(evt.text.unicode);
                std::string str = this->text.getString() + c;
                this->text.setString(str);
                break;
            }

            case sf::Event::KeyPressed:
            {
                printf("TEST");
                if(evt.key.code == sf::Keyboard::BackSpace) {
                    std::string str = this->text.getString();
                    str = str.substr(0, str.size() - 1);
                    this->text.setString(str);
                }
                break;
            }

            default:
            break;
        }
    } else {
        button.setTexture(normal);
    }
}

void TextArea::draw(sf::RenderWindow &window)
{
    window.draw(button);
    window.draw(text);
}

// a terminer
void TextArea::areaFocused()
{
    hasFocus = true;
}

void TextArea::areaUnfocused()
{

}
