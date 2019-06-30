#include "LoadSaveScreen.hpp"

LoadSaveScreen::LoadSaveScreen() {
  this->backgroundShape.setPosition(sf::Vector2f(0, 0));
  this->backgroundShape.setSize(sf::Vector2f(800, 800));
  this->backgroundShape.setFillColor(sf::Color(119, 119, 119));
  this->backgroundLines.push_back(Line(0, 0, 6, 800));
  this->backgroundLines.push_back(Line(0, 0, 800, 6));
  this->backgroundLines.push_back(Line(794, 0, 6, 800));
  this->backgroundLines.push_back(Line(0, 794, 800, 6));
  for (size_t i = 0; i < this->backgroundLines.size(); i++)
    this->backgroundLines.at(i).setColor(101, 101, 101);
  
  this->buttonClose = new ButtonClose(713, 31);
  this->buttonLoad = new ButtonLoad(310, 415);
  this->buttonSave = new ButtonSave(430, 415);

}


void LoadSaveScreen::handleClick(sf::Event e) {
  int x = e.mouseButton.x,
      y = e.mouseButton.y;
  
  if (x >= 713 && x < 773 && y >= 31 && y < 91)
    ScreenManager::getInstance().setActiveScreen(ScreenType::PlayScreen);
  if (x >= 310 && x < 370 && y >= 415 && y < 475)
    GameManager::getInstance().loadSavegame(this->textBox.getText()->getString().toAnsiString());
  if (x >= 430 && x < 490 && y >= 415 && y < 475)
    GameManager::getInstance().saveProgress(this->textBox.getText()->getString().toAnsiString());
  
}

void LoadSaveScreen::handleText(sf::Event e) {
  sf::Text *text = this->textBox.getText();
  size_t size = text->getString().getSize();
  if (e.text.unicode == 8) {
    if (size > 0)
      text->setString(
        text->getString().substring(0, size-1)
      );
  } else {
    text->setString(
      text->getString() + static_cast<char>(e.text.unicode)
    );
  }
}

void LoadSaveScreen::draw(sf::RenderWindow &window) {
  window.draw(this->backgroundShape);
  for (size_t i = 0; i < this->backgroundLines.size(); i++) {
    this->backgroundLines.at(i).draw(window);
  }
  this->textBox.draw(window);
  this->buttonClose->draw(window);
  this->buttonLoad->draw(window);
  this->buttonSave->draw(window);
}