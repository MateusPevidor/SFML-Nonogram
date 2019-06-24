#include "PlayScreen.hpp"

void PlayScreen::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}

PlayArea PlayScreen::getPlayArea() {
  return this->playArea;
}

void PlayScreen::draw(sf::RenderWindow &window) {
  this->playArea.draw(window);
}