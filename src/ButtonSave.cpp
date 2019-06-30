#include "ButtonSave.hpp"

ButtonSave::ButtonSave() {}

ButtonSave::ButtonSave(int x, int y) : Button(x, y) {
  this->position.x = x + 9;
  this->position.y = y + 8;
  this->sprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/button_save.png"));
  this->sprite.setPosition(this->position);
}

void ButtonSave::draw(sf::RenderWindow &window) {
  Button::draw(window);
  window.draw(this->sprite);
}