#include "PlayScreen.hpp"

void indexFromProperties(PlayAreaProperties props, int *i, int *j, int x, int y);

void PlayScreen::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}

PlayArea PlayScreen::getPlayArea() {
  return this->playArea;
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
  }
}

void PlayScreen::draw(sf::RenderWindow &window) {
  this->playArea.draw(window);
}

void indexFromProperties(PlayAreaProperties props, int *i, int *j, int x, int y) {
  x -= props.position.x;
  y -= props.position.y;
  *i = y / props.cellSize;
  *j = x / props.cellSize;
}