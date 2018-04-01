#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
    current = NULL;
}

ScreenManager::~ScreenManager()
{
    for (std::vector<Screen *>::iterator it = screens.begin(); it != screens.end(); it++)
        delete *it;
}

ScreenManager * ScreenManager::instance = NULL;

ScreenManager * ScreenManager::getInstance()
{
    if (instance == NULL)
        instance = new ScreenManager();
    return instance;
}

void ScreenManager::add(Screen *screen)
{
    screens.push_back(screen);
}

void ScreenManager::switchTo(std::string name)
{
    for (std::vector<Screen *>::iterator it = screens.begin(); it != screens.end(); it++)
    {
        if ((*it)->getName().compare(name) == 0) {
            current = *it;
            break;
        }
    }
}

Screen * ScreenManager::getCurrent()
{
    if (current == NULL && screens.size() > 0)
        current = screens[0];

    if (current && !current->isContentLoaded())
        current->loadContent();
    return current;
}
