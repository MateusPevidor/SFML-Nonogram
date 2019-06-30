#include "GameManager.hpp"

#include <iostream>

GameManager::GameManager() {}

GameManager& GameManager::getInstance() {
  static GameManager instance;
  return instance;
}

void GameManager::loadGameAssets() {
  FontManager::getInstance().addFont("../assets/fonts/Square.ttf");
  FontManager::getInstance().addFont("../assets/fonts/FORCED SQUARE.ttf");
  TextureManager::getInstance().addTexture("../assets/images/button_cross.png");
  TextureManager::getInstance().addTexture("../assets/images/button_hint.png");
  TextureManager::getInstance().addTexture("../assets/images/button_load.png");
  TextureManager::getInstance().addTexture("../assets/images/button_pause.png");
  TextureManager::getInstance().addTexture("../assets/images/button_save.png");
  TextureManager::getInstance().addTexture("../assets/images/button_template.png");
  TextureManager::getInstance().addTexture("../assets/images/field_cross.png");
  LevelManager::getInstance().loadCustomLevel("level1");
  LevelManager::getInstance().loadCustomLevel("level2");
  LevelManager::getInstance().loadCustomLevel("level3");
  LevelManager::getInstance().loadCustomLevel("level4");
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

void GameManager::saveProgress(std::string filename) {
  PlayArea playArea = this->getPlayArea();
  std::ofstream outFile;
  outFile.open("../levels/save/" + filename);
  outFile << LevelManager::getInstance().getCurrentLevelName() << std::endl;
  for (size_t i = 0; i < playArea.getCells().size(); i++) {
    for (size_t j = 0; j < playArea.getCells().at(i).size(); j++) {
      if (playArea.getCells().at(i).at(j).getState() == 1)
        outFile << "x";
      else if (playArea.getCells().at(i).at(j).getState() == 2)
        outFile << "-";
      else
        outFile << ".";
    }
    outFile << std::endl;
  }
}

void GameManager::loadSavegame(std::string filename) {
  std::string levelName;
  std::ifstream inFile("../levels/save/" + filename);
  char aux;
  if (inFile.is_open()) {
    inFile >> levelName;
    if (levelName == "") return;
    this->generatePlayArea(levelName);
    PlayScreen *p = (PlayScreen *) ScreenManager::getInstance().getScreen(Screen::PlayScreen);
    for (size_t i = 0; i < p->getPlayAreaAddress()->getCells().size(); i++) {
      for (size_t j = 0; j < p->getPlayAreaAddress()->getCells().at(i).size(); j++) {
        inFile >> aux;
        if (aux == 'x') {
          p->getPlayAreaAddress()->changeCellState(i, j, 1);
        } else if (aux == '-') {
          p->getPlayAreaAddress()->changeCellState(i, j, 2);
        }
      }
    }
    std::cout << p->getPlayAreaAddress() << std::endl;
    for (size_t i = 0; i < p->getPlayAreaAddress()->getColHeaders().size(); i++)
      p->getPlayAreaAddress()->updateHeaders(0, i);
    for (size_t i = 0; i < p->getPlayAreaAddress()->getRowHeaders().size(); i++)
      p->getPlayAreaAddress()->updateHeaders(i, 0);
    // for (int i = 0; i < this->getPlayArea().getCells().size(); i++) {
    //   for (int j = 0; j < this->getPlayArea().getCells().at(i).size(); j++) {
    //     std::cout << this->getPlayArea().getCells().at(i).at(j).getState();
    //   }
    //   std::cout << std::endl;
    // }
    ScreenManager::getInstance().setActiveScreen(Screen::ScreenType::PlayScreen);
  } else {
    
  }
}