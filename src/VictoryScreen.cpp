#include "VictoryScreen.hpp"

VictoryScreen::VictoryScreen() {
  this->backgroundShape.setPosition(sf::Vector2f(0, 0));
  this->backgroundShape.setSize(sf::Vector2f(800, 800));
  this->backgroundShape.setFillColor(sf::Color(119, 119, 119));
  this->backgroundLines.push_back(Line(0, 0, 6, 800));
  this->backgroundLines.push_back(Line(0, 0, 800, 6));
  this->backgroundLines.push_back(Line(794, 0, 6, 800));
  this->backgroundLines.push_back(Line(0, 794, 800, 6));
  for (size_t i = 0; i < this->backgroundLines.size(); i++)
    this->backgroundLines.at(i).setColor(101, 101, 101);

  message.setFont(FontManager::getInstance().getFont("../assets/fonts/FORCED SQUARE.ttf"));
  message.setCharacterSize(90);
  message.setString("YOU WIN!!");
}

void VictoryScreen::draw(sf::RenderWindow &window) {
  window.draw(this->backgroundShape);
  for (size_t i = 0; i < this->backgroundLines.size(); i++) {
    this->backgroundLines.at(i).draw(window);
  }
  window.draw(this->message);
}