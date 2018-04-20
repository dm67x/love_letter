#ifndef NEXTPLAYERMESSAGESCREEN_H
#define NEXTPLAYERMESSAGESCREEN_H

#include "Screen.h"

class NextPlayerMessageScreen : public Screen
{

private:
    sf::RectangleShape txt_background;
    sf::Text next_player_turn_msg;

    float timer = 0.0f;

    sf::Font font;

public:
    NextPlayerMessageScreen();
    ~NextPlayerMessageScreen();

    void loadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // NEXTPLAYERMESSAGESCREEN_H
