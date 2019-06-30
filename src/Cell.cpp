#include "Cell.hpp"
#include <iostream>

Cell::Cell(int x, int y, int w, int h) {
  this->position.x = x;
  this->position.y = y;
  this->dimensions.x = w;
  this->dimensions.y = h;
  this->shape.setPosition(this->position);
  this->shape.setSize(this->dimensions);
  this->shape.setFillColor(sf::Color(181, 181, 181));

  this->state = 0;
  
  this->crossSprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/field_cross.png"));
  this->crossSprite.setPosition(sf::Vector2f(this->position.x + w * 0.126, this->position.y + h * 0.126)); // Posiciona o X no centro do quadrado
  this->crossSprite.setScale(sf::Vector2f(w/65.0*0.745, h/65.0*0.745)); // Redimensiona a imagem

}

void Cell::draw(sf::RenderWindow &window) {
  if (this->state == 1)
    window.draw(this->shape);
  else if (this->state == 2)
    window.draw(this->crossSprite);
}

int Cell::getState() {
  return this->state;
}

void Cell::setState(int state) {
  this->state = state;
}

sf::Vector2f Cell::getPosition() {
  return this->position;
}