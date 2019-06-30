#include "Button.hpp"

Button::Button() {}

Button::Button(int x, int y) {
  this->position.x = x;
  this->position.y = y;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_template.png"));
  this->sprite.setPosition(this->position);
}
void Button::draw(sf::RenderWindow &window) {
  window.draw(this->sprite);
}