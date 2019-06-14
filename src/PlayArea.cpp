#include "PlayArea.hpp"
#include <iostream>

PlayArea::PlayArea(int lines, int cols, int guideSize) {

  TextureManager::getInstance().addTexture("../assets/images/field_cross.png");

  this->position.x = 50;
  this->position.y = 116;
  TextureManager::getInstance().addTexture("../assets/images/play_area.png");
  this->backgroundSprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/play_area.png"));
  this->backgroundSprite.setPosition(this->position);

  float cellSize = (lines > cols) ? 622/(guideSize + lines) : 622/(guideSize + cols);

  for (int j = 0; j < lines; j++) {
    std::vector <Quadrado> q;
    this->quadrados.push_back(q);
    for (int i = 0; i < cols; i++) {
      this->quadrados.at(j).push_back(Quadrado(
        (this->position.x + 4 + guideSize * cellSize + i * cellSize + i*2),
        (this->position.y + 4 + guideSize * cellSize + j * cellSize + j*2),
        cellSize, cellSize));
      this->quadrados.at(0).at(0).setState(2);
    }
  }
}

void PlayArea::draw(sf::RenderWindow &window) {
  window.draw(backgroundSprite);

  for (int i = 0; i < quadrados.size(); i++) {
    for (int j = 0; j < quadrados.at(i).size(); j++) {
      quadrados.at(i).at(j).draw(window);
    }
  }
}
