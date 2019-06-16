#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "PlayArea.hpp"
#include "LevelManager.hpp"

class GameManager {
  private:
    GameManager();
    PlayArea playArea;

  public:
    static GameManager& getInstance();
    void generatePlayArea(std::string levelID); // Cria a play area baseada nas dimensões do nome do nível
    PlayArea getPlayArea();
    void setPlayArea(PlayArea playArea);

};

#endif