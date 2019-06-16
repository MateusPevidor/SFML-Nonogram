#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager() {

}

GameManager& GameManager::getInstance() {
  static GameManager instance;
  return instance;
}

void GameManager::generatePlayArea(int rows, int cols, int guideSize) {
  PlayArea generatedPlayArea(rows, cols, guideSize);
  this->setPlayArea(generatedPlayArea);
}

PlayArea GameManager::getPlayArea() {
  return this->playArea;
}

void GameManager::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}