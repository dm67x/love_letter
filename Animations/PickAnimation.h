#ifndef PICK_ANIMATION_H
#define PICK_ANIMATION_H

#include "Animation.h"

class PickAnimation : public Animation
{

private:
    const float target_scale = 0.5f;
    float scale_speed;
    float move_speed;
    float scale;
    float current_scale;
    sf::Vector2f position;
    float current_position_y;

public:
    PickAnimation(sf::Sprite * object);
    PickAnimation(sf::Sprite * object, sf::Vector2f to_position);

	void update(float dt);

};

#endif
