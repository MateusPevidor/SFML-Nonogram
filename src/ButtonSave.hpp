#ifndef BUTTON_SAVE_HPP
#define BUTTON_SAVE_HPP

#include "Button.hpp"

class ButtonSave : public Button {
  private:
    sf::Sprite sprite;
    sf::Vector2f position;
  public:
    ButtonSave();
    ButtonSave(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif