#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

class MainWindow : public sf::RenderWindow
{

private:
    MainWindow();

    static MainWindow * instance;

public:
    static MainWindow * getInstance();

    void setFullscreen();

};

#endif // MAINWINDOW_H
