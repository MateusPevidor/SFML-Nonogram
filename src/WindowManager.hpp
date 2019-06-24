#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <SFML/Graphics.hpp>

class WindowManager {
  private:
    WindowManager();
    sf::RenderWindow *window;
  public:
    static WindowManager& getInstance();
    void setWindow(sf::RenderWindow*);
    sf::RenderWindow* getWindow();
};

#endif