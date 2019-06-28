#include "Line.hpp"

Line::Line(int x, int y, int w, int h) {
  this->position.x = x;
  this->position.y = y;
  this->dimensions.x = w;
  this->dimensions.y = h;

  this->shape.setPosition(this->position);
  this->shape.setSize(this->dimensions);
  this->shape.setFillColor(sf::Color(151, 151, 151));
}

void Line::setColor(int r, int g, int b) {
  this->shape.setFillColor(sf::Color(r, g, b));
}

void Line::draw(sf::RenderWindow &window) {
  window.draw(this->shape);
}