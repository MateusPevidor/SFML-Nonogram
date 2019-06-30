#include "LevelManager.hpp"
#include <iostream>

LevelManager::LevelManager() {}

LevelManager& LevelManager::getInstance() {
  static LevelManager instance;
  return instance;
}

void LevelManager::loadCustomLevel(std::string levelName) {
  std::ifstream inFile;
  Level level;

  inFile.open("../levels/" + levelName + ".txt");
  
  int rows, cols, counter, value;
  int maxCounter = 0;
  
  inFile >> rows >> cols; // Pega as dimensões do tabuleiro
  for (int i = 0; i < rows; i++) { // Itera uma vez para cada linha
    inFile >> counter;
    if (counter > maxCounter) maxCounter = counter;
    std::vector <int> headers;
    for (int j = 0; j < counter; j++) {
      inFile >> value;
      headers.push_back(value);
    }
    level.insertRowHeader(headers);
  }
  for (int i = 0; i < cols; i++) { // Itera uma vez para cada coluna
    inFile >> counter;
    std::vector <int> headers;
    for (int j = 0; j < counter; j++) {
      inFile >> value;
      headers.push_back(value);
    }
    level.insertColHeader(headers);
  }
  level.setColCount(cols);
  level.setRowCount(rows);
  level.setGuideSize(maxCounter);
  this->storeLevel(levelName, level);

}

void LevelManager::storeLevel(std::string id, Level level) {
  std::pair <std::string, Level> newEntry = std::pair <std::string, Level>(id, level);
  this->levels.insert(newEntry);
}

void LevelManager::loadLevels() {

}

Level LevelManager::getLevel(std::string id) {
  Level level = this->levels.at(id);
  return level;
}

Level LevelManager::getCurrentLevel() {
  return this->getLevel(this->currentLevel);
}

void LevelManager::setCurrentLevel(std::string levelName) {
  this->currentLevel = levelName;
}

std::string LevelManager::getCurrentLevelName() {
  return this->currentLevel;
}