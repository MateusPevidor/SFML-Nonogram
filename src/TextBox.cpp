#include "TextBox.hpp"

TextBox::TextBox() {
  
  this->setupText();

  this->backgroundShape.setPosition(sf::Vector2f(87, 310));
  this->backgroundShape.setSize(sf::Vector2f(626, 90));
  this->backgroundShape.setFillColor(sf::Color(87, 87, 87));
  this->backgroundLines.push_back(Line(87, 310, 3, 90));
  this->backgroundLines.push_back(Line(87, 310, 626, 3));
  this->backgroundLines.push_back(Line(710, 310, 3, 90));
  this->backgroundLines.push_back(Line(87, 397, 626, 3));
  for (size_t i = 0; i < this->backgroundLines.size(); i++)
    this->backgroundLines.at(i).setColor(101, 101, 101);
}

void TextBox::setupText() {
  this->text.setFont(FontManager::getInstance().getFont("../assets/fonts/FORCED SQUARE.ttf"));
  this->text.setCharacterSize(30);
  this->text.setPosition(120, 332);
  this->headerText.setFont(FontManager::getInstance().getFont("../assets/fonts/FORCED SQUARE.ttf"));
  this->headerText.setCharacterSize(45);
  this->headerText.setPosition(145, 245);
  this->headerText.setString("Insira o nome do arquivo:");
  this->loadButtonText.setFont(FontManager::getInstance().getFont("../assets/fonts/FORCED SQUARE.ttf"));
  this->loadButtonText.setCharacterSize(20);
  this->loadButtonText.setPosition(320, 470);
  this->loadButtonText.setString("Load");
  this->saveButtonText.setFont(FontManager::getInstance().getFont("../assets/fonts/FORCED SQUARE.ttf"));
  this->saveButtonText.setCharacterSize(20);
  this->saveButtonText.setPosition(440, 470);
  this->saveButtonText.setString("Save");

}

sf::Text* TextBox::getText() {
  return &this->text;
}

void TextBox::draw(sf::RenderWindow &window) {
  window.draw(this->backgroundShape);
  for (size_t i = 0; i < this->backgroundLines.size(); i++) {
    this->backgroundLines.at(i).draw(window);
  }
  window.draw(this->text);
  window.draw(this->headerText);
  window.draw(this->loadButtonText);
  window.draw(this->saveButtonText);
}