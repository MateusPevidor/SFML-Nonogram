#include "ButtonHint.hpp"

ButtonHint::ButtonHint() {}

ButtonHint::ButtonHint(int x, int y) : Button(x, y) {
  this->position.x = x + 16;
  this->position.y = y + 9;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_hint.png"));
  this->sprite.setPosition(this->position);
}

void ButtonHint::draw(sf::RenderWindow &window) {
  Button::draw(window);
  window.draw(this->sprite);
}