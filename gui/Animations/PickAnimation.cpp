#include "PickAnimation.h"

PickAnimation::PickAnimation(sf::Sprite * object)
    : PickAnimation(object, sf::Vector2f(0, 0))
{
}

PickAnimation::PickAnimation(sf::Sprite * object, sf::Vector2f to_position)
    : Animation(1.0f, object)
{
    move_animation = new MoveAnimation(1.0f, object, to_position);
    scale_animation = new ScaleAnimation(1.0f, object, sf::Vector2f(0.5f, 0.5f));
}

void PickAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        move_animation->start();
        scale_animation->start();

        move_animation->update(dt);
        scale_animation->update(dt);
    }
}
