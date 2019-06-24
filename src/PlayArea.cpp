#include "PlayArea.hpp"
#include <iostream>

PlayArea::PlayArea() {}

PlayArea::PlayArea(int rows, int cols, int guideSize) {

  TextureManager::getInstance().addTexture("../assets/images/field_cross.png");

  // Cálculo do tamanho de cada célula do campo
  float cellSize = (rows > cols) ? 622.0/(guideSize + rows) : 622.0/(guideSize + cols);
  cellSize = floor(cellSize);
  properties.cellSize = cellSize;

  // Cálculo do tamanho e posição do campo em função da quantidade de células
  if (cols > rows) {
    this->dimensions.x = 622;
    this->dimensions.y = 622 - (cellSize * (cols-rows));
    this->position.y = 116 + (cellSize * (cols-rows))/2;
    this->position.x = 50;
  } else {
    this->dimensions.x = 622 - (cellSize * (rows-cols));
    this->dimensions.y = 622;
    this->position.x = 50 + (cellSize * (rows-cols))/2;
    this->position.y = 112;
  }

  this->properties.limits = this->dimensions + this->position + sf::Vector2f(6, 6);

  // Criação da imagem de fundo
  this->background.setPosition(sf::Vector2f(this->position.x + 6, this->position.y + 6));
  this->background.setSize(this->dimensions);
  this->background.setFillColor(sf::Color(79, 79, 79));
  this->borders.push_back(Line(this->position.x, this->position.y, 6, this->dimensions.y + 12));  // Esquerda
  this->borders.push_back(Line(this->dimensions.x + this->position.x + 6, this->position.y, 6, this->dimensions.y + 12)); // Direita
  this->borders.push_back(Line(this->position.x, this->position.y, this->dimensions.x + 12, 6));  // Superior
  this->borders.push_back(Line(this->position.x, this->dimensions.y + this->position.y + 6, this->dimensions.x + 12, 6));  // Inferior
  
  int offsetX = cellSize-2 + this->position.x + 6 + guideSize * cellSize + (cols-1) * cellSize - (this->dimensions.x + this->position.x + 6);
  int offsetY = cellSize-2 + this->position.y + 6 + guideSize * cellSize + (rows-1) * cellSize - (this->dimensions.y + this->position.y + 6);

  this->importHeaders(cellSize, guideSize, offsetX, offsetY);
  this->properties.dimensions.x = this->colHeaders.size();
  this->properties.dimensions.y = this->rowHeaders.size();

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
  this->properties.position.x = this->position.x + 6 - offsetX + guideSize * cellSize;
  this->properties.position.y = this->position.y + 6 - offsetY + guideSize * cellSize;

  // Criação das linhas que dividem o tabuleiro
  int w;
  for (int i = 0; i <= cols; i++) { // Linhas verticais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(Line(
      this->position.x + 4 - offsetX + guideSize * cellSize + (i) * cellSize,
      this->position.y + 6, w, this->dimensions.y));
  }

  for (int i = 0; i <= rows; i++) { // Linhas Horizontais
    w = (i == 0) ? 4 : 2;
    this->guideLines.push_back(Line(
      this->position.x + 6,
      this->position.y + 4 - offsetY + guideSize * cellSize + (i) * cellSize,
      this->dimensions.x, w));
  }
}

void PlayArea::importHeaders(float cellSize, int guideSize, int offsetX, int offsetY) {
  Level currentLevel = LevelManager::getInstance().getCurrentLevel();
  for (int i = 0; i < (int) currentLevel.getColHeaders().size(); i++) {
    std::vector <Header> temp;
    for (int j = 0; j < (int) currentLevel.getColHeaders().at(i).size(); j++) {
      temp.push_back(Header(
        currentLevel.getColHeaders().at(i).at(currentLevel.getColHeaders().at(i).size()-j-1),
        sf::Vector2f(
          this->position.x + (cellSize * guideSize) + cellSize*(i) + 6 - offsetX,
          this->position.y + cellSize*(guideSize-j-1) + 8 - offsetY
        ),
      cellSize));
    }
    this->colHeaders.push_back(temp);
  }

  for (int i = 0; i < (int) currentLevel.getRowHeaders().size(); i++) {
    std::vector <Header> temp;
    for (int j = 0; j < (int) currentLevel.getRowHeaders().at(i).size(); j++) {
      temp.push_back(Header(
        currentLevel.getRowHeaders().at(i).at(currentLevel.getRowHeaders().at(i).size()-j-1),
        sf::Vector2f(
          this->position.x + cellSize*(guideSize-j-1) + 6 - offsetY,
          this->position.y + (cellSize * guideSize) + cellSize*(i) + 6 - offsetX
        ),
      cellSize));
    }
    this->rowHeaders.push_back(temp);
  }
}

void PlayArea::changeCellState(int i, int j, int state) {
  if (this->cells.at(i).at(j).getState() == 0)
    this->cells.at(i).at(j).setState(state);
  else if (this->cells.at(i).at(j).getState() == 1 && state == 1)
    this->cells.at(i).at(j).setState(0);
  else if (this->cells.at(i).at(j).getState() == 2 && state == 2)
    this->cells.at(i).at(j).setState(0);
}

void PlayArea::draw(sf::RenderWindow &window) {
  // Fundo
  window.draw(background);
  for (unsigned int i = 0; i < this->borders.size(); i++)
    this->borders.at(i).draw(window);

  // Quadrados
  for (unsigned int i = 0; i < this->cells.size(); i++)
    for (unsigned int j = 0; j < this->cells.at(i).size(); j++)
      this->cells.at(i).at(j).draw(window);

  // Linhas divisoras
  for (unsigned int i = 0; i < this->guideLines.size(); i++)
    this->guideLines.at(i).draw(window);

  // Cabeçalhos
  for (unsigned int i = 0; i < this->colHeaders.size(); i++) // das colunas
    for (unsigned int j = 0; j < this->colHeaders.at(i).size(); j++)
      this->colHeaders.at(i).at(j).draw(window);

  for (unsigned int i = 0; i < this->rowHeaders.size(); i++) // das linhas
    for (unsigned int j = 0; j < this->rowHeaders.at(i).size(); j++)
      this->rowHeaders.at(i).at(j).draw(window);
}

PlayAreaProperties PlayArea::getProperties() {
  return this->properties;
}