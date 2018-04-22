#ifndef RULESSCREEN_H
#define RULESSCREEN_H

#include "Screen.h"

class RulesScreen : public Screen
{

private:
    sf::Font font;
    sf::Text text_loveletter;
    sf::Text text_seiji;
    sf::Text text_rules;
    sf::Text text_cards;
    sf::Text text_title;

    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

    const float space = 20.0f;

public:
    RulesScreen();
    ~RulesScreen();

    void loadContent();
    void input(sf::Event evt);
    void draw(sf::RenderWindow &window);

};

#endif // RULESSCREEN_H
