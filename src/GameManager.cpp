#include "GameManager.hpp"


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
  for (int i = 0; i < generatedPlayArea.getProperties().dimensions.y; i++)
    for (int j = 0; j < generatedPlayArea.getProperties().dimensions.x; j++)
      generatedPlayArea.updateHeaders(i, j);
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
    for (size_t i = 0; i < p->getPlayAreaAddress()->getColHeaders().size(); i++)
      p->getPlayAreaAddress()->updateHeaders(0, i);
    for (size_t i = 0; i < p->getPlayAreaAddress()->getRowHeaders().size(); i++)
      p->getPlayAreaAddress()->updateHeaders(i, 0);

    ScreenManager::getInstance().setActiveScreen(Screen::ScreenType::PlayScreen);
  } else {
    
  }
}

void GameManager::fillZeros(PlayArea *playArea, bool mustSolve) {
  for (int i = 0; i < playArea->getProperties().dimensions.y; i++)
    if (!atoi(playArea->getRowHeaders().at(i).at(0).text.getString().toAnsiString().c_str())) {
      if (mustSolve)
        for (int j = 0; j < playArea->getProperties().dimensions.x; j++)
          playArea->forceCellState(i, j, 2);
      playArea->getRowHeaders().at(i).at(0).isSolved = true;
      playArea->getRowHeaders().at(i).at(0).setSolved(true);
    }
  
  for (int j = 0; j < playArea->getProperties().dimensions.x; j++)
    if (!atoi(playArea->getColHeaders().at(j).at(0).text.getString().toAnsiString().c_str())) {
      if (mustSolve)
        for (int i = 0; i < playArea->getProperties().dimensions.y; i++)
          playArea->forceCellState(i, j, 2);
      playArea->getColHeaders().at(j).at(0).isSolved = true;
      playArea->getRowHeaders().at(j).at(0).setSolved(true);
    }

}

void GameManager::solve() {
  PlayScreen *p = (PlayScreen*) ScreenManager::getInstance().getScreen(Screen::PlayScreen);
  PlayArea *playArea = p->getPlayAreaAddress();
  for (int i = 0; i < playArea->getProperties().dimensions.x; i++) {
    int count = playArea->getColHeaders().at(i).size() - 1;
    for (size_t j = 0; j < playArea->getColHeaders().at(i).size(); j++) {
      count += atoi(playArea->getColHeaders().at(i).at(j).text.getString().toAnsiString().c_str());
    }
    if (count == playArea->getProperties().dimensions.y)
      this->fillCol(i, playArea);
    else if (playArea->getColHeaders().at(i).size() == 1)
      this->fillHalfCol(i, playArea);
  }

  for (int i = 0; i < playArea->getProperties().dimensions.y; i++) {
    int count = playArea->getRowHeaders().at(i).size() - 1;
    for (size_t j = 0; j < playArea->getRowHeaders().at(i).size(); j++) {
      count += atoi(playArea->getRowHeaders().at(i).at(j).text.getString().toAnsiString().c_str());
    }
    if (count == playArea->getProperties().dimensions.x)
      this->fillRow(i, playArea);
    else if (playArea->getRowHeaders().at(i).size() == 1)
      this->fillHalfRow(i, playArea);
  }

  for (size_t i = 0; i < playArea->getColHeaders().size(); i++)
    playArea->updateHeaders(0, i);
  for (size_t i = 0; i < playArea->getRowHeaders().size(); i++)
    playArea->updateHeaders(i, 0);

  this->fillZeros(playArea, true);
  this->solveCompleteHeaders(playArea);
}

void GameManager::fillCol(int j, PlayArea* playArea) {
  int index = 0;
  for (size_t i = 0; i < playArea->getColHeaders().at(j).size(); i++) {
    for (int k = 0; k < atoi(playArea->getColHeaders().at(j).at(playArea->getColHeaders().at(j).size()-i-1).text.getString().toAnsiString().c_str()); k++) {
      playArea->forceCellState(index, j, 1);
      index++;
    }
    if (i < playArea->getColHeaders().at(j).size() - 1)
      playArea->forceCellState(index, j, 2);
    index++;
  }
}

void GameManager::fillRow(int i, PlayArea* playArea) {
  int index = 0;
  for (size_t j = 0; j < playArea->getRowHeaders().at(i).size(); j++) {
    for (int k = 0; k < atoi(playArea->getRowHeaders().at(i).at(playArea->getRowHeaders().at(i).size()-j-1).text.getString().toAnsiString().c_str()); k++) {
      playArea->forceCellState(i, index, 1);
      index++;
    }
    if (j < playArea->getRowHeaders().at(i).size() - 1)
      playArea->forceCellState(i, index, 2);
    index++;
  }
}

void GameManager::fillHalfCol(int j, PlayArea* playArea) {
  int total = playArea->getProperties().dimensions.y;
  int val = atoi(playArea->getColHeaders().at(j).at(0).text.getString().toAnsiString().c_str());
  if (val > total / 2) {
    for (int i = total-val; i < val; i++) {
      playArea->forceCellState(i, j, 1);
    }
  }
}

void GameManager::fillHalfRow(int i, PlayArea* playArea) {
  int total = playArea->getProperties().dimensions.x;
  int val = atoi(playArea->getRowHeaders().at(i).at(0).text.getString().toAnsiString().c_str());
  if (val > total / 2) {
    for (int j = total-val; j < val; j++) {
      playArea->forceCellState(i, j, 1);
    }
  }
}

void GameManager::solveCompleteHeaders(PlayArea* playArea) {
  for (int j = 0; j < playArea->getProperties().dimensions.x; j++)
    if (playArea->getColHeaders().at(j).at(0).isSolved)
      for (int i = 0; i < playArea->getProperties().dimensions.y; i++)
        if (playArea->getCells().at(i).at(j).getState() == 0)
          playArea->forceCellState(i, j, 2);
  
  for (int i = 0; i < playArea->getProperties().dimensions.y; i++)
    if (playArea->getRowHeaders().at(i).at(0).isSolved)
      for (int j = 0; j < playArea->getProperties().dimensions.x; j++)
        if (playArea->getCells().at(i).at(j).getState() == 0)
          playArea->forceCellState(i, j, 2);
}