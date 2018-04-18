#include "TextArea.h"

TextArea::TextArea(sf::Vector2f position)
{
    // No limit
    this->character_number_limit = -1;

    // Default
    this->text_area_width = 200;

    construct(position);  
}

TextArea::TextArea(sf::Vector2f position, unsigned int cnl)
{
    this->character_number_limit = cnl;

    // Default
    this->text_area_width = 200;

    construct(position);   
}

TextArea::TextArea(sf::Vector2f position, unsigned int cnl, int taw)
{
    this->character_number_limit = cnl;

    // Default
    this->text_area_width = taw;

    construct(position);
}

void TextArea::construct(sf::Vector2f position) {
    n_color = sf::Color(226, 26, 57);

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

    this->background.setSize(sf::Vector2f(text_area_width, 35));
    this->background.setFillColor(sf::Color::White);
    this->background.setPosition(sf::Vector2f(this->text.getGlobalBounds().left - 8.0f,
                                              this->text.getGlobalBounds().top));
    this->background.setOutlineThickness(1);
    this->background.setOutlineColor(sf::Color::Black);
}

TextArea::~TextArea()
{

}

std::string TextArea::getText()
{
    std::string str = this->text.getString();
    return str;
}

void TextArea::update(sf::Event evt)
{
    if(hasFocus) {
        this->background.setOutlineThickness(2);
        this->background.setOutlineColor(sf::Color::Blue);
    } else {
        this->background.setOutlineThickness(1);
        this->background.setOutlineColor(sf::Color::Black);
    }

    switch (evt.type)
    {
        case sf::Event::TextEntered:
        {
            if(hasFocus) {
                if(evt.text.unicode < 127 && evt.text.unicode > 31) {
                    char c = static_cast<char>(evt.text.unicode);
                    std::string str = this->text.getString() + c;

                    // Test if there is too many characters
                    if(this->character_number_limit == (unsigned)-1
                            || str.size() <= this->character_number_limit) {

                        // Test if letter is outside of text area
                        if((this->text.getGlobalBounds().width + 30.0f)
                                < this->background.getGlobalBounds().width) {

                            this->text.setString(str);
                            sf::sleep(sf::milliseconds(100));
                        }
                    }
                }
            }
            break;
        }

        case sf::Event::KeyPressed:
        {
            if(hasFocus) {
                if(evt.key.code == sf::Keyboard::BackSpace) {
                    std::string str = this->text.getString();
                    str = str.substr(0, str.size() - 1);
                    this->text.setString(str);
                }
            }
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            if (evt.mouseButton.button == sf::Mouse::Left) {
                hasFocus = this->isMouseInside(sf::Vector2i(evt.mouseButton.x,
                                                            evt.mouseButton.y));
            }
            break;
        }

        default:
        break;
    }

}

bool TextArea::isMouseInside(sf::Vector2i mouse_pos)
{
    sf::FloatRect bg_rect = this->background.getGlobalBounds();

    if(mouse_pos.x > bg_rect.left && mouse_pos.x < bg_rect.left + bg_rect.width
            && mouse_pos.y > bg_rect.top && mouse_pos.y < bg_rect.top + bg_rect.height) {
        return true;
    } else {
        return false;
    }
}

void TextArea::draw(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(text);
}
