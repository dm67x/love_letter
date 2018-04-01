#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.h"
#include "Button.h"

class MenuScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    Button * singleplayer_button;
    static void singleplayerButtonClicked();

    Button * multiplayer_button;
    static void multiplayerButtonClicked();

    Button * credits_button;
    static void creditsButtonClicked();

    Button * quit_button;
    static void quitButtonClicked();

public:
    MenuScreen();
    ~MenuScreen();

    void loadContent();
    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // MENUSCREEN_H
