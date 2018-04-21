#ifndef SINGLEPLAYERMODECHOICESCREEN_H
#define SINGLEPLAYERMODECHOICESCREEN_H

#include "Screen.h"
#include "Buttons/MenuButton.h"
#include "Button.h"

class SingleplayerModeChoiceScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    Button * play_vs_humans_button;
    static void play_vs_humansButtonClicked();
    Button * play_solo_vs_ai_button;
    static void play_solo_vs_aiButtonClicked();

    sf::Font font;

    const float space_between_menu = 70.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    SingleplayerModeChoiceScreen();
    ~SingleplayerModeChoiceScreen();

    void loadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow & window);

    static const int players_number = 2;

};

#endif // SINGLEPLAYERMODECHOICESCREEN_H
