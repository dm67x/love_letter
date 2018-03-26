#ifndef HOVER_ANIMATION_H
#define HOVER_ANIMATION_H

#include "ScaleAnimation.h"

class HoverAnimation : public Animation
{

private:
    ScaleAnimation * scale_animation;

public:
    HoverAnimation(sf::Sprite * object);

    void update(float dt);

};

#endif // HOVER_ANIMATION_H
