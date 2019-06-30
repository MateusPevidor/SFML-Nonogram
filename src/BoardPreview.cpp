#include "BoardPreview.hpp"

BoardPreview::BoardPreview(int rows, int cols, sf::Vector2f position, sf::Vector2f dimensions) {
  
  int cellSize = (rows > cols) ? dimensions.y / rows : dimensions.x / cols;
  int offsetX = (dimensions.x - (cellSize * cols)) / 2;
  int offsetY = (dimensions.y - (cellSize * rows)) / 2;
  
  for (int i = 0; i < rows; i++) {
    std::vector <Cell> q;
    for (int j = 0; j < cols; j++) {
      q.push_back(Cell(
        position.x + cellSize*j + offsetX,
        position.y + cellSize*i + offsetY,
        cellSize, cellSize
      ));
    }
    this->cells.push_back(q);
  }
}

std::vector <std::vector <Cell>> BoardPreview::getCells() {
  return this->cells;
}

void BoardPreview::updateCell(int i, int j, int state) {
  this->cells.at(i).at(j).setState(state);
}

void BoardPreview::draw(sf::RenderWindow &window) {
  for (size_t i = 0; i < this->cells.size(); i++)
    for (size_t j = 0; j < this->cells.at(i).size(); j++)
      this->cells.at(i).at(j).draw(window);
}