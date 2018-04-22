#include "GuessDialog.h"
#include "core/cards/all.h"
#include "MainWindow.h"

#include <iostream>

GuessDialog::GuessDialog(sf::Vector2f size)
    : DialogBox("Use right and left to move card", size)
{
    name = "";
    cards_pos = sf::Vector2f(-size.x / 4.0f - 10, 0.0f);

    cards.push_back(new Card(new Core::Priest()));
    cards.push_back(new Card(new Core::Baron()));
    cards.push_back(new Card(new Core::Handmaid()));
    cards.push_back(new Card(new Core::Prince()));
    cards.push_back(new Card(new Core::King()));
    cards.push_back(new Card(new Core::Countess()));
    cards.push_back(new Card(new Core::Princess()));

    int i = 0;
    for (auto it = cards.begin(); it < cards.end(); it++) {
        (*it)->setScale(0.5f, 0.5f);
        (*it)->reveal();
        sf::Vector2f dimensions = (*it)->getDimensions();
        (*it)->move((dimensions.x + 10) * i + cards_pos.x, 0.0f);
        i++;
    }
}

void GuessDialog::close()
{
    DialogBox::close();
    name = "";
}

void GuessDialog::input(sf::Event evt)
{
    if (evt.type == sf::Event::MouseButtonPressed
            && evt.mouseButton.button == sf::Mouse::Left) {

        sf::Vector2i mpos = sf::Vector2i(evt.mouseButton.x, evt.mouseButton.y);

        for (auto it = cards.begin(); it != cards.end(); it++) {
            sf::Vector2f position = getTransform().transformPoint((*it)->getPosition());
            sf::Vector2f dimension = (*it)->getDimensions();
            sf::FloatRect rect = sf::FloatRect(position.x - dimension.x / 2.0f,
                                               position.y - dimension.y / 2.0f,
                                               dimension.x, dimension.y);
            if ((position.x - dimension.x) >= size.x / 4.0f && position.x <= size.x * 1.25f) {
                if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                    name = (*it)->getCard()->getName();
                    std::cout << name << std::endl;
                    break;
                }
            }
        }

    }

    if (evt.type == sf::Event::KeyPressed) {
        if (evt.key.code == sf::Keyboard::Right)
            cards_pos.x -= 10;
        else if (evt.key.code == sf::Keyboard::Left)
            cards_pos.x += 10;

        int i = 0;
        for (auto it = cards.begin(); it < cards.end(); it++) {
            sf::Vector2f dimensions = (*it)->getDimensions();
            (*it)->setPosition(
                        (dimensions.x + 10) * i + cards_pos.x,
                        cards_pos.y);
            i++;
        }
    }
}

void GuessDialog::update(float dt)
{
    sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow());

    for (auto it = cards.begin(); it != cards.end(); it++) {
        sf::Vector2f position = getTransform().transformPoint((*it)->getPosition());
        sf::Vector2f dimension = (*it)->getDimensions();
        sf::FloatRect rect = sf::FloatRect(position.x - dimension.x / 2.0f,
                                           position.y - dimension.y / 2.0f,
                                           dimension.x, dimension.y);
        if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
            (*it)->setHover(true);
            break;
        } else {
            (*it)->setHover(false);
        }
    }
}

void GuessDialog::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    if (is_open) {
        for (auto it = cards.begin(); it != cards.end(); it++) {
            sf::Vector2f position = getTransform().transformPoint((*it)->getPosition());
            sf::Vector2f dim = (*it)->getDimensions();
            if ((position.x - dim.x) >= size.x / 4.0f && position.x <= size.x * 1.25f)
                target.draw(*(*it), states);
        }
    }
}
