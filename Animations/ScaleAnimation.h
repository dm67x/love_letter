#ifndef SCALEANIMATION_H
#define SCALEANIMATION_H

#include "Animation.h"

class ScaleAnimation : public Animation
{

private:
    sf::Vector2f scale_speed;
    sf::Vector2f scale;
    sf::Vector2f updated_scale;

public:
    ScaleAnimation(sf::Sprite * object, sf::Vector2f to);
    ScaleAnimation(float duration, sf::Sprite * object, sf::Vector2f to);

    void update(float dt);

};

#endif // SCALEANIMATION_H
