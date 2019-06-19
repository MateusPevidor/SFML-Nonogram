#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include <vector>
#include <map>
#include <fstream>
#include "Level.hpp"

class LevelManager {
  private:
    LevelManager();
    std::map <std::string, Level> levels;
    std::string currentLevel;

  public:
    static LevelManager& getInstance();
    void loadCustomLevel(std::string levelName); // Carrega nível a partir do nome do arquivo
    void loadLevels(); // Carrega todos os níveis no diretório "levels"
    void storeLevel(std::string id, Level level); // Armazena um nível no map
    Level getLevel(std::string id);
    Level getCurrentLevel();
    void setCurrentLevel(std::string levelName);
};

#endif