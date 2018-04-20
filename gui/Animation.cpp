#include "Animation.h"

Animation::Animation(float time, sf::Sprite * object)
{
	this->time = time;
    current = 0.0f;
    this->object = object;
    state = NOT_LAUNCH;
}

Animation::~Animation()
{
}

void Animation::start()
{
    state = START;
}

void Animation::update(float dt)
{
    if (state == START || state == PLAYING) {
        state = PLAYING;
        current += dt;
        if (current >= time) {
			stop();
		}
    }
}

void Animation::stop()
{
    state = STOP;
    current = 0.0f;
}

enum ANIM_STATE Animation::getState()
{
    return state;
}

void Animation::setState(ANIM_STATE state)
{
    this->state = state;
}

float Animation::in_cubic_ease(float t, float b, float c, float d)
{
    t /= d;
    return b+c*t*t*t;
}
