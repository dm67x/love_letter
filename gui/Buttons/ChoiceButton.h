#ifndef CHOICEBUTTON_H
#define CHOICEBUTTON_H

#include "Button.h"

class ChoiceButton
{

private:
    sf::Texture normal, hover;
    sf::Text choice_text;
    sf::Font font;
    sf::Color n_color, h_color;

public:
    ChoiceButton(std::string choice_text, int choice_number, sf::Vector2f position);
    ~ChoiceButton();

    void update();
    void draw(sf::RenderWindow &window);

};

#endif // CHOICEBUTTON_H
