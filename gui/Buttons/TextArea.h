#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "Button.h"

class TextArea : public Button
{

private:
    sf::Sprite button;
    sf::Texture normal, hover;
    sf::Text text;
    sf::Font font;
    sf::Color n_color, h_color;

    sf::RectangleShape background;
    int text_area_width;

    unsigned int character_number_limit;

    bool hasFocus;
    bool firstFocus;

public:
    TextArea(sf::Vector2f position);
    TextArea(sf::Vector2f position, unsigned int cnl);
    TextArea(sf::Vector2f position, unsigned int cnl, int taw);
    ~TextArea();

    std::string getText();
    bool isMouseInside(sf::Vector2i mouse_pos);

    void construct(sf::Vector2f position);

    void update(sf::Event evt);
    void draw(sf::RenderWindow &window);

};

#endif // TEXTAREA_H
