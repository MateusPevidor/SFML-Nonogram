#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager() {}

GameManager& GameManager::getInstance() {
  static GameManager instance;
  return instance;
}

void GameManager::generatePlayArea(std::string levelID) {
  Level level = LevelManager::getInstance().getLevel(levelID);
  int rows = level.getRowCount(),
      cols = level.getColCount(),
      guideSize = level.getGuideSize();
  
  PlayArea generatedPlayArea(rows, cols, guideSize);
  this->setPlayArea(generatedPlayArea);
}

PlayArea GameManager::getPlayArea() {
  return this->playArea;
}

void GameManager::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}