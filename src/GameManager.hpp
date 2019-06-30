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
    void saveProgress(std::string filename);
    void loadSavegame(std::string filename);
};

#endif