#ifndef MENU_SCREEN_HPP
#define MENU_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class MenuScreen : public Screen {
  private:
    
  public:
    void draw(sf::RenderWindow &window);
};

#endif