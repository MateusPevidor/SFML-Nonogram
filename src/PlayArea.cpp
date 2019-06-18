#include "PlayArea.hpp"
#include <iostream>

PlayArea::PlayArea() {}

PlayArea::PlayArea(int rows, int cols, int guideSize) {

  TextureManager::getInstance().addTexture("../assets/images/field_cross.png");

  this->position.x = 50;
  this->position.y = 116;

  // Cálculo do tamanho de cada célula do campo
  float cellSize = (rows > cols) ? 622.0/(guideSize + rows) : 622.0/(guideSize + cols);
  cellSize = floor(cellSize);
  std::cout << cellSize << std::endl;

  float max = (rows>cols) ? rows + guideSize : cols + guideSize;
  float trg = (rows>cols) ? cols + guideSize : rows + guideSize;
  float x = 622 * trg/max;
  std::cout << max << " " << trg << " " << x << std::endl;
  this->background.setPosition(sf::Vector2f(this->position.x + 6, this->position.y + 6));
  this->background.setSize(sf::Vector2f(622, 622));
  if (rows > cols)
    this->background.setScale(sf::Vector2f(x/622, 1));
  else
    this->background.setScale(sf::Vector2f(1, x/622));
  this->background.setFillColor(sf::Color(79, 79, 79));
  this->borders.push_back(Line(50, 116, 6, 634));
  this->borders.push_back(Line(50, 116, 634, 6));
  this->borders.push_back(Line(50, 744, 634, 6));
  this->borders.push_back(Line(678, 116, 6, 634));
  

  int offsetX = cellSize-2 + this->position.x + 6 + guideSize * cellSize + (cols-1) * cellSize - 678;
  int offsetY = cellSize-2 + this->position.y + 6 + guideSize * cellSize + (rows-1) * cellSize - 744;
  for (int j = 0; j < rows; j++) { // Criação da matriz de quadrados
    std::vector <Cell> q;
    this->cells.push_back(q);
    for (int i = 0; i < cols; i++) {
      this->cells.at(j).push_back(Cell(
        (this->position.x + 6 - offsetX + guideSize * cellSize + i * cellSize),
        (this->position.y + 6 - offsetY + guideSize * cellSize + j * cellSize),
        cellSize-2, cellSize-2));
    }
  }

  // Criação das linhas que dividem o tabuleiro
  int w;
  for (int i = 0; i <= cols; i++) { // Linhas verticais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(Line(
      this->position.x + 4 - offsetX + guideSize * cellSize + (i) * cellSize,
      this->position.y + 6, w, 622));
  }

  for (int i = 0; i <= rows; i++) { // Linhas Horizontais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(Line(
      this->position.x + 6,
      this->position.y + 4 - offsetY + guideSize * cellSize + (i) * cellSize,
      622, w));
  }
}

void PlayArea::draw(sf::RenderWindow &window) {
  window.draw(background);
  for (int i = 0; i < this->borders.size(); i++)
    this->borders.at(i).draw(window);

  for (int i = 0; i < this->cells.size(); i++) {
    for (int j = 0; j < this->cells.at(i).size(); j++) {
      this->cells.at(i).at(j).draw(window);
    }
  }

  for (int i = 0; i < this->guideLines.size(); i++) {
    this->guideLines.at(i).draw(window);
  }
}
