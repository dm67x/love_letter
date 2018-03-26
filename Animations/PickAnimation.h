#ifndef PICK_ANIMATION_H
#define PICK_ANIMATION_H

#include "MoveAnimation.h"
#include "ScaleAnimation.h"

class PickAnimation : public Animation
{

private:
    MoveAnimation * move_animation;
    ScaleAnimation * scale_animation;

public:
    PickAnimation(sf::Sprite * object);
    PickAnimation(sf::Sprite * object, sf::Vector2f to_position);

	void update(float dt);

};

#endif
