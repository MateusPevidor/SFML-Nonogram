#include "PlayScreen.hpp"

PlayScreen::PlayScreen() {
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
  this->buttonPause = new ButtonPause(641, 31);
  this->buttonHint = new ButtonHint(713, 713);
  this->buttonSave = new ButtonSave(713, 641);
}

void indexFromProperties(PlayAreaProperties props, int *i, int *j, int x, int y);

void PlayScreen::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}

PlayArea PlayScreen::getPlayArea() {
  return this->playArea;
}

PlayArea* PlayScreen::getPlayAreaAddress() {
  return &this->playArea;
}

void PlayScreen::handleClick(sf::Event e) {
  PlayAreaProperties props = this->playArea.getProperties();
  int x = e.mouseButton.x,
      y = e.mouseButton.y;
  if (x >= props.position.x && x <= props.limits.x && y >= props.position.y && y <= props.limits.y) {
    int i, j, state;
    indexFromProperties(props, &i, &j, x, y);
    state = (e.mouseButton.button) ? 2 : 1;
    this->playArea.changeCellState(i, j, state);
    this->playArea.updateHeaders(i, j);
    if (GameManager::getInstance().checkWin())
      ScreenManager::getInstance().setActiveScreen(Screen::VictoryScreen);
  }
  if (x >= 713 && x < 773 && y >= 31 && y < 91)
    WindowManager::getInstance().getWindow()->close();
  // if (x >= 641 && x < 701 && y >= 31 && y < 91) BOTAO DE PAUSE
  if (x >= 713 && x < 773 && y >= 713 && y < 773)
    GameManager::getInstance().solve();
  if (x >= 713 && x < 773 && y >= 641 && y < 701)
    ScreenManager::getInstance().setActiveScreen(ScreenType::LoadSaveScreen);


}

void PlayScreen::draw(sf::RenderWindow &window) {
  window.draw(this->backgroundShape);
  for (size_t i = 0; i < this->backgroundLines.size(); i++) {
    this->backgroundLines.at(i).draw(window);
  }
  this->playArea.draw(window);
  this->buttonClose->draw(window);
  this->buttonPause->draw(window);
  this->buttonHint->draw(window);
  this->buttonSave->draw(window);
}

void indexFromProperties(PlayAreaProperties props, int *i, int *j, int x, int y) {
  x -= props.position.x;
  y -= props.position.y;
  *i = y / props.cellSize;
  *j = x / props.cellSize;
}