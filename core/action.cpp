#include "action.h"
#include <cstdlib>

Action::Action()
{
    empty();
}

Action * Action::instance = NULL;

Action * Action::getInstance()
{
    if (instance == NULL)
        instance = new Action();
    return instance;
}

void Action::empty()
{
    current = NULL;
    target = NULL;
    c1 = NULL;
    c2 = NULL;
}
