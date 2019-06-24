#include "GameManager.hpp"
#include "ScreenManager.hpp"
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
  
  LevelManager::getInstance().setCurrentLevel(levelID);
  PlayArea generatedPlayArea(rows, cols, guideSize);
  PlayScreen *p = (PlayScreen *) ScreenManager::getInstance().getScreen(Screen::PlayScreen);
  p->setPlayArea(generatedPlayArea);
}

PlayArea GameManager::getPlayArea() {
  PlayScreen *p = (PlayScreen *) ScreenManager::getInstance().getScreen(Screen::PlayScreen);
  return p->getPlayArea();
}

void GameManager::setPlayArea(PlayArea playArea) {
  this->playArea = playArea;
}