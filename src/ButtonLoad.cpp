#include "ButtonLoad.hpp"

ButtonLoad::ButtonLoad() {}

ButtonLoad::ButtonLoad(int x, int y) : Button(x, y) {
  this->position.x = x + 7;
  this->position.y = y + 7;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_load.png"));
  this->sprite.setPosition(this->position);
}

void ButtonLoad::draw(sf::RenderWindow &window) {
  Button::draw(window);
  window.draw(this->sprite);
}