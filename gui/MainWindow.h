#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

class MainWindow
{

private:
    sf::RenderWindow * window;

    MainWindow();

    static MainWindow * instance;

public:
    static MainWindow * getInstance();

    inline sf::RenderWindow * getWindow() const { return window; }

    void setFullscreen();

};

#endif // MAINWINDOW_H
