#ifndef SINGLEPLAYERMENUSCREEN_H
#define SINGLEPLAYERMENUSCREEN_H

#include "Screen.h"
#include "Buttons\MenuButton.h"
#include "Button.h"

class SingleplayermenuScreen : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    sf::Text number_players_choice_text;
    sf::Color number_players_choice_color;

    static MenuButton * two_players_button;
    static void two_playersButtonClicked();
    static MenuButton * three_players_button;
    static void three_playersButtonClicked();
    static MenuButton * four_players_button;
    static void four_playersButtonClicked();

    sf::Font font;

    Button * play_button;
    static void playButtonClicked();

    const float space_between_menu = 70.0f;
    const float space_players_choice = 30.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    SingleplayermenuScreen();
    ~SingleplayermenuScreen();

    static int players_number;

    void loadContent();
    void update(sf::Event evt, float dt);
    void draw(sf::RenderWindow & window);

};

#endif // SINGLEPLAYERMENUSCREEN_H
