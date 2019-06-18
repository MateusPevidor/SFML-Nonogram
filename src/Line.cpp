#include "Line.hpp"

Line::Line(int x, int y, int w, int h) {
  this->position.x = x;
  this->position.y = y;
  this->dimensions.x = w;
  this->dimensions.y = h;

  this->shape.setPosition(this->position);
  this->shape.setSize(this->dimensions);
  this->shape.setFillColor(sf::Color(126, 126, 126));
}

void Line::draw(sf::RenderWindow &window) {
  window.draw(this->shape);
}