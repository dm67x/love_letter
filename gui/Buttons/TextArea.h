#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "Object.h"

class TextArea : public Object
{

private:
    sf::Text text;
    sf::Font font;
    sf::Color n_color;

    sf::RectangleShape background;
    int text_area_width;

    unsigned int character_number_limit;

    bool hasFocus;

public:
    TextArea(sf::Vector2f position);
    TextArea(sf::Vector2f position, unsigned int cnl);
    TextArea(sf::Vector2f position, unsigned int cnl, int taw);
    ~TextArea();

    std::string getText();
    bool isMouseInside(sf::Vector2i mouse_pos);

    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // TEXTAREA_H
