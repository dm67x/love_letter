#include "Card.h"
#include <sstream>

Card::Card(Core::Card *card)
    : Object("card")
{    
    this->card = card;
    is_reveal = false;
    animation = NULL;
    hover = false;
    m_show = true;

    // shader
    hover_shader.loadFromFile("data/hover.frag", sf::Shader::Fragment);
    hover_shader.setUniform("texture", sf::Shader::CurrentTexture);

    // textures
    switch (card->getValue()) {
    case 1:
        texture.loadFromFile("data/guard.jpg");
        break;

    case 2:
        texture.loadFromFile("data/priest.jpg");
        break;

    case 3:
        texture.loadFromFile("data/baron.jpg");
        break;

    case 4:
        texture.loadFromFile("data/handmaid.jpg");
        break;

    case 5:
        texture.loadFromFile("data/prince.jpg");
        break;

    case 6:
        texture.loadFromFile("data/king.jpg");
        break;

    case 7:
        texture.loadFromFile("data/countess.jpg");
        break;

    case 8:
        texture.loadFromFile("data/princess.jpg");
        break;
    }
    back_texture.loadFromFile("data/back_card.jpg");

    card_sprite.setTexture(back_texture);

    // set origin center of texture
    card_sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

    // Load font
    font.loadFromFile("data/Another day in Paradise.ttf");

    // title
    title.setFont(font);
    title.setFillColor(sf::Color::Black);
    title.setString(card->getName());
    title.setCharacterSize(30);
    sf::FloatRect title_rect = title.getLocalBounds();
    title.setOrigin(title_rect.left + title_rect.width / 2, title_rect.top + title_rect.height / 2);
    title.setPosition(getPosition() - sf::Vector2f(0.0f, 175.0f));

    // description
    description.setFont(font);
    description.setFillColor(sf::Color::Black);
    description.setCharacterSize(24);

    // line wrapper
    std::string descr = card->getDescription();
    for (unsigned int i = 1; i < descr.size(); i++) {
        description.setString(descr.substr(0, i));
        sf::FloatRect desc = description.getLocalBounds();
        sf::FloatRect card_b = card_sprite.getLocalBounds();
        if (desc.left + desc.width >= card_b.left + card_b.width) {
            descr.insert(i-10, "\n");
        }
    }

    sf::FloatRect desc_rect = description.getLocalBounds();
    description.setOrigin(desc_rect.left + desc_rect.width / 2, desc_rect.top + desc_rect.height / 2);
    description.move(5.0f, texture.getSize().y / 2.0f - 65.0f);

    // value
    value.setFont(font);
    value.setFillColor(sf::Color::Black);
    std::ostringstream oss;
    oss << card->getValue();
    value.setString(oss.str());
    value.setCharacterSize(40);
    sf::FloatRect value_rect = value.getLocalBounds();
    value.setOrigin(value_rect.left + value_rect.width / 2, value_rect.top + value_rect.height / 2);
    sf::FloatRect card_bounds = card_sprite.getLocalBounds();
    value.move(card_bounds.left - card_bounds.width / 2.0f + 50.0f,
               card_bounds.top - card_bounds.height / 2.0f + 50.0f);
}

Card::~Card()
{
}

sf::Vector2f Card::getDimensions() const
{
    sf::Vector2u texture_s = texture.getSize();
    sf::Vector2f scale = getScale();
    return sf::Vector2f(texture_s.x * scale.x, texture_s.y * scale.y);
}

void Card::setAnimation(Animation *anim)
{
    animation = anim;
}

void Card::clearAnimation()
{
    if (animation) {
        delete animation;
        animation = NULL;
    }
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

void Card::setHover(bool hover)
{
    this->hover = hover;
}

void Card::show()
{
    m_show = true;
}

void Card::hide()
{
    m_show = false;
}

void Card::update(float dt)
{
    if (animation) {
        if (animation->getState() == NOT_LAUNCH)
            animation->start();
        animation->update(dt);
    }
}

void Card::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    if (hover)
        states.shader = &hover_shader;

    if (m_show) {
        target.draw(card_sprite, states);
        if (is_reveal) {
            target.draw(title, states);
            target.draw(description, states);
            target.draw(value, states);
        }
    }
}
