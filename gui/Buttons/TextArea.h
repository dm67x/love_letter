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

    int character_number_limit;

    bool hasFocus;

public:
    TextArea(sf::Vector2f position);
    TextArea(sf::Vector2f position, int cnl);
    ~TextArea();

    void update(sf::Event evt);
    void draw(sf::RenderWindow &window);

    void areaFocused();
    void areaUnfocused();

};

#endif // TEXTAREA_H
