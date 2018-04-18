#include "TextArea.h"
#include <sstream>
#include <string>

TextArea::TextArea(sf::Vector2f position)
    : Button(position)
{
    // No limit
    this->character_number_limit = -1;

    // Default
    this->text_area_width = 200;

    construct(position);  
}

TextArea::TextArea(sf::Vector2f position, unsigned int cnl)
    : Button(position)
{
    this->character_number_limit = cnl;

    // Default
    this->text_area_width = 200;

    construct(position);   
}

TextArea::TextArea(sf::Vector2f position, unsigned int cnl, int taw)
    : Button(position)
{
    this->character_number_limit = cnl;

    // Default
    this->text_area_width = taw;

    construct(position);
}

void TextArea::construct(sf::Vector2f position) {
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

    this->rect = this->text.getGlobalBounds();

    hasFocus = true;

    this->background.setSize(sf::Vector2f(text_area_width, 35));
    this->background.setFillColor(sf::Color(255, 255, 255));
    this->background.setPosition(sf::Vector2f(this->rect.left - 7.0f,
                                              this->rect.top));
    this->background.setOutlineThickness(1);
    this->background.setOutlineColor(sf::Color(0, 0, 0));
}

TextArea::~TextArea()
{

}

void TextArea::update(sf::Event evt)
{
    button.setTexture(normal);
    /* En attendant, le texte area aura toujours le focus
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (mouseInside()) {
                hasFocus = true;
        } else {
            hasFocus = false;
        }
    }*/

    if (hasFocus) {     
        switch (evt.type)
        {
            case sf::Event::TextEntered:
            {
                if(evt.text.unicode < 127 && evt.text.unicode > 31) {
                    char c = static_cast<char>(evt.text.unicode);
                    std::string str = this->text.getString() + c;

                    // Test if there is too many characters
                    if(this->character_number_limit == -1
                            || str.size() <= this->character_number_limit) {

                        // Test if letter is outside of text area
                        if((this->text.getGlobalBounds().width + 30.0f)
                                < this->background.getGlobalBounds().width) {

                            this->text.setString(str);
                            sf::sleep(sf::milliseconds(100));
                        }
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
    window.draw(background);
    window.draw(text);
}
