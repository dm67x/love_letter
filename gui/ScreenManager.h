#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"

class ScreenManager
{

private:
    static ScreenManager * instance; // for singleton
    Screen * current; // current screen
    std::vector<Screen *> screens; // list of screens

private:
    ScreenManager();

public:
    ~ScreenManager();
    static ScreenManager * getInstance();

    void add(Screen * screen);
    void switchTo(std::string name);
    Screen * getCurrent();

};

#endif // SCREENMANAGER_H
