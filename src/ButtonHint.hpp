#ifndef BUTTON_HINT_HPP
#define BUTTON_HINT_HPP

#include "Button.hpp"

class ButtonHint : public Button {
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
  public:
    ButtonHint();
    ButtonHint(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif