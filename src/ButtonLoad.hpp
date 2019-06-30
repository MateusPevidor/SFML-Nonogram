#ifndef BUTTON_LOAD_HPP
#define BUTTON_LOAD_HPP

#include "Button.hpp"

class ButtonLoad : public Button {
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
  public:
    ButtonLoad();
    ButtonLoad(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif