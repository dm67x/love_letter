#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.h"
#include "Button.h"

class MenuScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    Button * localgame_button;
    static void singleplayerButtonClicked();

    Button * multiplayer_button;
    static void multiplayerButtonClicked();

    Button * rules_button;
    static void rulesButtonClicked();

    Button * credits_button;
    static void creditsButtonClicked();

    Button * quit_button;
    static void quitButtonClicked();

    const float space_between_menu = 70.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    MenuScreen();
    ~MenuScreen();

    void loadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // MENUSCREEN_H
