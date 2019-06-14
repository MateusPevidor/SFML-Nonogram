#include "Quadrado.hpp"

Quadrado::Quadrado(int x, int y, int w, int h) {
  this->position.x = x;
  this->position.y = y;
  this->dimensions.x = w;
  this->dimensions.y = h;
  this->shape.setPosition(this->position);
  this->shape.setSize(this->dimensions);
  this->shape.setFillColor(sf::Color(163, 163, 163));

  this->state = 1;
  
  this->crossSprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/field_cross.png"));
  this->crossSprite.setPosition(sf::Vector2f(this->position.x + w * 0.126, this->position.y + h * 0.126)); // Posiciona o X no centro do quadrado
  this->crossSprite.setScale(sf::Vector2f(w/65.0*0.745, h/65.0*0.745)); // Redimensiona a imagem

}

// void Quadrado::updateTexture() {
//   this->crossSprite.setTexture(this->texture);
//   this->crossSprite.setPosition(sf::Vector2f(this->position.x * 1.126, this->position.y * 1.126)); // Posiciona o X no centro do quadrado
//   this->crossSprite.setScale(sf::Vector2f(this->dimensions.x/65.0*0.745, this->dimensions.y/65.0*0.745)); // Redimensiona a imagem
// }

void Quadrado::draw(sf::RenderWindow &window) {
  if (this->state == 1)
    window.draw(this->shape);
  else if (this->state == 2)
    window.draw(this->crossSprite);
}

int Quadrado::getState() {
  return this->state;
}

void Quadrado::setState(int state) {
  this->state = state;
}