#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "PlayArea.hpp"
#include "FontManager.hpp"
#include "LevelManager.hpp"
#include "ScreenManager.hpp"
#include "TextureManager.hpp"

class GameManager {
  private:
    GameManager();

  public:
    static GameManager& getInstance();
    void loadGameAssets();
    void generatePlayArea(std::string levelID); // Cria a play area baseada nas dimensões do nível
    PlayArea getPlayArea();
    void setPlayArea(PlayArea playArea);
    bool checkWin();
    void fillZeros(PlayArea *playArea, bool mustSolve);
    void solve();
    void fillCol(int j, PlayArea* playArea);
    void fillHalfCol(int j, PlayArea* playArea);
    void fillRow(int i, PlayArea* playArea);
    void fillHalfRow(int i, PlayArea* playArea);
    void solveCompleteHeaders(PlayArea* playArea);
    void saveProgress(std::string filename);
    void loadSavegame(std::string filename);
};

#endif