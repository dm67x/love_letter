#ifndef HOVER_ANIMATION_H
#define HOVER_ANIMATION_H

#include "Animation.h"

class HoverAnimation : public Animation
{

private:
    const float target_scale = 1.0f;
    float scale_speed;
    float current_scale;
    float scale;

public:
    HoverAnimation(sf::Sprite * object);

    void update(float dt);

};

#endif // HOVER_ANIMATION_H
