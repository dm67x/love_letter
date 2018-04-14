#ifndef SINGLEPLAYERMENUSCREEN_H
#define SINGLEPLAYERMENUSCREEN_H

#include "Screen.h"
#include "Button.h"

class SingleplayermenuScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    // TODO: Zone de texte

    Button * play_button;
    static void playButtonClicked();

    const float space_between_menu = 70.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    SingleplayermenuScreen();
    ~SingleplayermenuScreen();

    void loadContent();
    void update(sf::Event evt, float dt);
    void draw(sf::RenderWindow & window);

};

#endif // SINGLEPLAYERMENUSCREEN_H
