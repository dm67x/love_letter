#ifndef MOVEANIMATION_H
#define MOVEANIMATION_H

#include "Animation.h"

class MoveAnimation : public Animation
{

private:
    sf::Vector2f move_speed;
    sf::Vector2f position;
    sf::Vector2f updated_position;

public:
    MoveAnimation(sf::Sprite * object, sf::Vector2f to);
    MoveAnimation(float duration, sf::Sprite * object, sf::Vector2f to);

    void update(float dt);

};

#endif // MOVEANIMATION_H
