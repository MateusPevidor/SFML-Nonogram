#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "PlayArea.hpp"

class GameManager {
  private:
    GameManager();
    PlayArea playArea;

  public:
    static GameManager& getInstance();
    void generatePlayArea(int rows, int cols, int guideSize);
    PlayArea getPlayArea();
    void setPlayArea(PlayArea playArea);

};

#endif