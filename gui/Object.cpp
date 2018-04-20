#include "Object.h"

Object::Object(std::string id)
    : sf::Transformable(), sf::Drawable()
{
    this->id = id;
}

Object::~Object()
{
}

void Object::input(sf::Event evt)
{
    input(evt, sf::Transform::Identity);
}

void Object::input(sf::Event evt, sf::Transform transf)
{
    (void)evt;
    (void)transf;
}

void Object::update(float dt)
{
    update(dt, sf::Transform::Identity);
}

void Object::update(float dt, sf::Transform transf)
{
    (void)dt;
    (void)transf;
}
