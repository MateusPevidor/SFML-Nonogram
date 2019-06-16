#include "PlayArea.hpp"
#include <iostream>

PlayArea::PlayArea() {}

PlayArea::PlayArea(int rows, int cols, int guideSize) {

  TextureManager::getInstance().addTexture("../assets/images/field_cross.png");

  this->position.x = 50;
  this->position.y = 116;
  TextureManager::getInstance().addTexture("../assets/images/play_area.png");
  this->backgroundSprite.setTexture(TextureManager::getInstance().getTexture("../assets/images/play_area.png"));
  this->backgroundSprite.setPosition(this->position);

  // Cálculo do tamanho de cada célula do campo
  float cellSize = (rows > cols) ? 622.0/(guideSize + rows) : 622.0/(guideSize + cols);
  cellSize = floor(cellSize);
  

  int offsetX = cellSize-2 + this->position.x + 6 + guideSize * cellSize + (cols-1) * cellSize - 678;
  int offsetY = cellSize-2 + this->position.y + 6 + guideSize * cellSize + (rows-1) * cellSize - 744;
  // Criação do array 2D de quadrados
  for (int j = 0; j < rows; j++) {
    std::vector <Quadrado> q;
    this->quadrados.push_back(q);
    for (int i = 0; i < cols; i++) {
      this->quadrados.at(j).push_back(Quadrado(
        (this->position.x + 6 - offsetX + guideSize * cellSize + i * cellSize),
        (this->position.y + 6 - offsetY + guideSize * cellSize + j * cellSize),
        cellSize-2, cellSize-2));
    }
  }

  // Criação das linhas que dividem o tabuleiro
  int w;
  for (int i = 0; i <= cols; i++) { // Linhas verticais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(GuideLine(
      this->position.x + 4 - offsetX + guideSize * cellSize + (i) * cellSize,
      this->position.y + 7, w, 622));
  }

  for (int i = 0; i <= rows; i++) { // Linhas Horizontais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(GuideLine(
      this->position.x + 7,
      this->position.y + 4 - offsetY + guideSize * cellSize + (i) * cellSize,
      622, w));
  }
}

void PlayArea::draw(sf::RenderWindow &window) {
  window.draw(backgroundSprite);

  for (int i = 0; i < this->quadrados.size(); i++) {
    for (int j = 0; j < this->quadrados.at(i).size(); j++) {
      this->quadrados.at(i).at(j).draw(window);
    }
  }

  for (int i = 0; i < this->guideLines.size(); i++) {
    this->guideLines.at(i).draw(window);
  }
}
