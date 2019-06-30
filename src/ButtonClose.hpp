#ifndef BUTTON_CLOSE_HPP
#define BUTTON_CLOSE_HPP

#include "Button.hpp"

class ButtonClose : public Button {
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
  public:
    ButtonClose();
    ButtonClose(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif