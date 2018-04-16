#ifndef CREATEGAME_H
#define CREATEGAME_H

#include "Screen.h"
#include "Buttons\MenuButton.h"
#include "Button.h"

class CreateGame : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    sf::Text number_players_choice_text;
    sf::Color number_players_choice_color;

    static MenuButton * two_players_button;
    static void two_playersButtonclicked();
    static MenuButton * three_players_button;
    static void three_playersButtonclicked();
    static MenuButton * four_players_button;
    static void four_playersButtonclicked();

    sf::Font font;

    Button * play_button;
    static void playButtonClicked();

    const float space_between_menu = 70.0f;
    const float space_players_choice = 30.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    CreateGame();
    ~CreateGame();

    static int players_number_multi;

    void loadContent();
    void update(sf::Event evt, float dt);
    void draw(sf::RenderWindow & window);

};

#endif // CREATEGAME_H
