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

bool GameManager::checkWin() {
  PlayArea playArea = this->getPlayArea();
  for (size_t i = 0; i < playArea.getColHeaders().size(); i++)
    for (size_t j = 0; j < playArea.getColHeaders().at(i).size(); j++)
      if (!playArea.getColHeaders().at(i).at(j).isSolved) return false;
  
  for (size_t i = 0; i < playArea.getRowHeaders().size(); i++)
    for (size_t j = 0; j < playArea.getRowHeaders().at(i).size(); j++)
      if (!playArea.getRowHeaders().at(i).at(j).isSolved) return false;

  return true;
}