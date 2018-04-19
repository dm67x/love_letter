#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include "Screen.h"

class CreditsScreen : public Screen
{

private:
    sf::Font font;
    sf::Text text_loveletter;
    sf::Text text_seiji;
    sf::Text text_title;
    sf::Text text_dev1;
    sf::Text text_dev2;
    sf::Text text_dev3;
    sf::Text text_dev4;

    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

    const float space = 20.0f;

public:
    CreditsScreen();
    ~CreditsScreen();

    void loadContent();
    void input(sf::Event evt);
    void draw(sf::RenderWindow &window);

};

#endif // CREDITSSCREEN_H
