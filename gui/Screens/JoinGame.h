#ifndef JOINGAME_H
#define JOINGAME_H

#include "Screen.h"
#include "Buttons\MenuButton.h"
#include "Button.h"

class JoinGame : public Screen
{

private:
    sf::Sprite love_letter;
    sf::Texture love_letter_texture;

    sf::Font font;

    sf::Text ip_adress_text;
    sf::Color ip_adress_color;

    // TODO: ADD TEXT AREA

    Button * join_button;
    static void joinButtonClicked();

    const float space_between_menu = 70.0f;

    // Background
    sf::Sprite background;
    sf::Texture bg_texture;

public:
    JoinGame();
    ~JoinGame();

    static std::string player_ip_adress;

    void loadContent();
    void update(sf::Event evt, float dt);
    void draw(sf::RenderWindow & window);

};

#endif // JOINGAME_H
