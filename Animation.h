#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

enum ANIM_STATE { NOT_LAUNCH, START, STOP, PLAYING };

class Animation
{

protected:
    float time; // animation time
    float current; // current animation time
    enum ANIM_STATE state; // animation state
    sf::Sprite * object; // object to animate

public:
    Animation(float time, sf::Sprite * object);
    virtual ~Animation();

    void start();
	virtual void update(float dt);
    void stop();
    enum ANIM_STATE getState();
    void setState(enum ANIM_STATE state);

};

#endif
