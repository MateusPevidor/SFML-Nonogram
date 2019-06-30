#ifndef BUTTON_PAUSE_HPP
#define BUTTON_PAUSE_HPP

#include "Button.hpp"

class ButtonPause : public Button {
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
  public:
    ButtonPause();
    ButtonPause(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif