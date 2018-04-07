#include "Card.h"
#include <sstream>

Card::Card(Core::Card *card)
    : Drawable()
{
    this->card = card;
    is_reveal = false;
    animation = NULL;

    // textures
    texture.loadFromFile("data/guard.jpg");
    back_texture.loadFromFile("data/custom_dos.jpg");

    card_sprite.setTexture(back_texture);

    // set origin center of texture
    card_sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

    // Load font
    font.loadFromFile("data/BLKCHCRY.TTF");

    // title
    title.setFont(font);
    title.setFillColor(sf::Color::Black);
    title.setString(card->getName());
    title.setCharacterSize(24);
    sf::FloatRect title_rect = title.getLocalBounds();
    title.setOrigin(title_rect.left + title_rect.width / 2, title_rect.top + title_rect.height / 2);
    // TODO SET POSITION

    // description
    description.setFont(font);
    description.setFillColor(sf::Color::Black);
    description.setString(card->getDescription());
    description.setCharacterSize(24);
    sf::FloatRect desc_rect = description.getLocalBounds();
    description.setOrigin(desc_rect.left + desc_rect.width / 2, desc_rect.top + desc_rect.height / 2);
    // TODO SET POSITION

    // description
    value.setFont(font);
    value.setFillColor(sf::Color::Black);
    std::ostringstream oss;
    oss << card->getValue();
    value.setString(oss.str());
    value.setCharacterSize(24);
    sf::FloatRect value_rect = value.getLocalBounds();
    value.setOrigin(value_rect.left + value_rect.width / 2, value_rect.top + value_rect.height / 2);
    // TODO SET POSITION
}

Card::~Card()
{
}

void Card::setAnimation(Animation *anim)
{
    animation = anim;
}

void Card::clearAnimation()
{
    delete animation;
    animation = NULL;
}

void Card::reveal()
{
    card_sprite.setTexture(texture);
    is_reveal = true;
}

void Card::mask()
{
    card_sprite.setTexture(back_texture);
    is_reveal = false;
}

void Card::setPosition(float px, float py)
{
    card_sprite.setPosition(px, py);
}

void Card::setPosition(sf::Vector2f position)
{
    card_sprite.setPosition(position);
}

void Card::setScale(float sx, float sy)
{
    card_sprite.setScale(sx, sy);
}

void Card::update(float dt)
{
    (void)dt;
}

void Card::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(card_sprite, states);
    if (is_reveal) {
        target.draw(title, states);
        target.draw(description, states);
        target.draw(value, states);
    }
}
