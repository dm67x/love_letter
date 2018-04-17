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

    hasFocus = true;

    // No limit
    this->character_number_limit = -1;
}

TextArea::TextArea(sf::Vector2f position, int cnl)
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

    hasFocus = true;

    this->character_number_limit = cnl;
}

TextArea::~TextArea()
{

}

void TextArea::update(sf::Event evt)
{
    Button::update();

    if (hasFocus) {
        button.setTexture(normal);

        switch (evt.type)
        {
            case sf::Event::TextEntered:
            {
                if(evt.text.unicode < 127 && evt.text.unicode > 31) {
                    char c = static_cast<char>(evt.text.unicode);
                    std::string str = this->text.getString() + c;
                    if(this->character_number_limit == -1
                            || str.size() <= this->character_number_limit) {
                        this->text.setString(str);
                        sf::sleep(sf::milliseconds(100));
                    }
                }
                break;
            }

            case sf::Event::KeyPressed:
            {
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
