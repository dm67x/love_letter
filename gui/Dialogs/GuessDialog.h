#ifndef GUESSDIALOG_H
#define GUESSDIALOG_H

#include "DialogBox.h"
#include "Elements/Card.h"

class GuessDialog : public DialogBox
{

private:
    std::vector<Card *> cards;
    std::string name;
    sf::Vector2f cards_pos;

public:
    GuessDialog(sf::Vector2f size);

    inline std::string getClickedCardName() const { return name; }

    void close();

    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // GUESSDIALOG_H
