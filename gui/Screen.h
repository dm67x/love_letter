#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen
{

private:
    std::string screen_name; // name of screen (example: game_screen)

protected:
    bool content_loaded; // boolean to know if contents of this screen is loaded

protected:
    Screen(std::string name);

public:
    virtual ~Screen();

    inline std::string getName() const { return screen_name; }
    inline bool isContentLoaded() const { return content_loaded; }
    sf::Vector2u getSize();

    virtual void loadContent();
    virtual void unloadContent();
    virtual void input(sf::Event evt);
    virtual void update(float dt);
    virtual void draw(sf::RenderWindow & window) = 0;

};

#endif // SCREEN_H
