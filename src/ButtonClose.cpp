#include "ButtonClose.hpp"

ButtonClose::ButtonClose() {}

ButtonClose::ButtonClose(int x, int y) : Button(x, y) {
  this->position.x = x + 11;
  this->position.y = y + 11;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_cross.png"));
  this->sprite.setPosition(this->position);
}

void ButtonClose::draw(sf::RenderWindow &window) {
  Button::draw(window);
  window.draw(this->sprite);
}