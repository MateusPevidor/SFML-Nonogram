#include "Header.hpp"
#include "FontManager.hpp"
#include <iostream>

Header::Header() {}

Header::Header(int value, sf::Vector2f position, float cellSize) {
  this->text.setFont(FontManager::getInstance().getFont("../assets/fonts/Square.ttf"));
  this->text.setString(std::to_string(value));
  this->text.setCharacterSize(cellSize*70/89);
  this->text.setFillColor(sf::Color(163, 163, 163));
  this->text.setPosition(
    position.x - this->text.getGlobalBounds().left + cellSize/2 - this->text.getGlobalBounds().width/2,
    position.y - this->text.getGlobalBounds().top + cellSize/2 - this->text.getGlobalBounds().height/2
  );
}

void Header::draw(sf::RenderWindow &window) {
  window.draw(this->text);
}