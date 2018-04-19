#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "Button.h"

class MenuButton : public Button
{

private:
    sf::Sprite button;
    sf::Texture normal, hover;
    sf::Text text;
    sf::Font font;
    sf::Color n_color, h_color, p_color;

    bool isPressed;

public:
    MenuButton(std::string text, sf::Vector2f position);
    ~MenuButton();

    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void buttonPressed();
    void buttonUnpressed();
};

#endif // MENUBUTTON_H
