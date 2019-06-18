#include "Header.hpp"
#include "FontManager.hpp"
#include <iostream>

Header::Header() {}

Header::Header(int value) {
  this->text.setFont(FontManager::getInstance().getFont("../assets/fonts/Square.ttf"));
  this->text.setString(std::to_string(value));
  this->text.setCharacterSize(70);
  this->text.setFillColor(sf::Color(163, 163, 163));
  
  // sf::Text text2;
  // sf::Font font = FontManager::getInstance().getFont("../assets/fonts/Square.ttf");
  // text2.setFont(font);
  // text2.setCharacterSize(70);
  // text2.setFillColor(sf::Color(163, 163, 163));
  // text2.setString("asd");
  // this->text = text2;
}

void Header::draw(sf::RenderWindow &window) {
  window.draw(this->text);
}