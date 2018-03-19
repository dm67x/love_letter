#include "action.h"
#include <cstdlib>

Action * Action::instance = NULL;

Action * Action::getInstance()
{
    if (instance == NULL)
        instance = new Action();
    return instance;
}

void Action::clear()
{
    current = target = NULL;
    guess.empty();
}

Action::Action()
{
    clear();
}
