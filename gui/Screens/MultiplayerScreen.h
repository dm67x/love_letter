#ifndef MULTIPLAYERSCREEN_H
#define MULTIPLAYERSCREEN_H

#include "Screen.h"
#include "Button.h"

class MultiplayerScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    Button * create_game_button;
    static void create_gameButtonClicked();

    Button * join_game_button;
    static void join_gameButtonClicked();

    const float space_between_menu = 70.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    MultiplayerScreen();
    ~MultiplayerScreen();

    void loadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // MULTIPLAYERSCREEN_H
