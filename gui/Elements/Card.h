#ifndef CARD_H
#define CARD_H

/**
  * Ajouter une fonction de click sur les cartes (pour les jouer notamment)
  */

#include "Object.h"
#include "core/card.h"
#include "Animation.h"

class Card : public Object
{

private:
    Core::Card * card; // card from lib core, title, value and description
    sf::Sprite card_sprite;
    sf::Texture texture; // texture of card
    sf::Texture back_texture; // texture for the back of cards (dos de carte)
    sf::Text title, description, value; // title, description, value
    sf::Font font; // font to use
    bool is_reveal; // if true show card (title, description...) else show card's back
    Animation * animation; // animation on card

    // Hover
    sf::Shader hover_shader;
    bool hover;

    bool m_show;

public:
    Card(Core::Card * card);
    ~Card();

    inline Animation * getAnimation() const { return animation; }
    inline sf::Sprite * getSprite() { return &card_sprite; }
    inline Core::Card * getCard() const { return card; }
    sf::Vector2f getDimensions() const;

    void setAnimation(Animation * anim);
    void clearAnimation();
    void reveal();
    void mask();
    void setHover(bool hover);
    void show();
    void hide();

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // CARD_H
