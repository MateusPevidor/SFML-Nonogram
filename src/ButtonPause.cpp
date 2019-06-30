#include "ButtonPause.hpp"

ButtonPause::ButtonPause() {}

ButtonPause::ButtonPause(int x, int y) : Button(x, y) {
  this->position.x = x + 15;
  this->position.y = y + 15;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_pause.png"));
  this->sprite.setPosition(this->position);
}

void ButtonPause::draw(sf::RenderWindow &window) {
  Button::draw(window);
  window.draw(this->sprite);
}