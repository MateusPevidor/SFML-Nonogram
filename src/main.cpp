#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>

#include "EventManager.hpp"
#include "FontManager.hpp"
#include "GameManager.hpp"
#include "LevelManager.hpp"
#include "ScreenManager.hpp"
#include "TextureManager.hpp"
#include "WindowManager.hpp"

#include "Header.hpp"

#define LEVEL "level1"

int main(int argc, char* argv[]) {
  
  sf::RenderWindow window(
    sf::VideoMode(800, 800),
    "UltimatePix",
    sf::Style::Titlebar | sf::Style::Close
  );
  window.setVerticalSyncEnabled(1);
  WindowManager::getInstance().setWindow(&window);

  GameManager::getInstance().loadGameAssets();

  ScreenManager::getInstance().createScreens();
  ScreenManager::getInstance().setActiveScreen(Screen::PlayScreen);

  if (argc != 1) { // Carrega o nível se ele foi passado por parâmetro na execução
    LevelManager::getInstance().loadCustomLevel(argv[1]);
    GameManager::getInstance().generatePlayArea(argv[1]);
  } else { // Carrega o nível do #define se nenhum parâmetro foi passado (tem que ser carregado no GameManager::getInstance().loadGameAssets())
    GameManager::getInstance().generatePlayArea(LEVEL);
  }



  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      EventManager::getInstance().handleEvent(event);
    }

    window.clear();
    
    ScreenManager::getInstance().drawScreen(*WindowManager::getInstance().getWindow());
    
    window.display();
  }

  return 0;
}