#include <ctime>
#include <cstdlib>
#include <iostream>
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

  FontManager::getInstance().addFont("../assets/fonts/Square.ttf");
  LevelManager::getInstance().loadCustomLevel(LEVEL);
  ScreenManager::getInstance().createScreens();
  ScreenManager::getInstance().setActiveScreen(Screen::PlayScreen);

  GameManager::getInstance().generatePlayArea(LEVEL);


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      EventManager::getInstance().handleEvent(event);
    }

    window.clear();
    
    // GameManager::getInstance().getPlayArea().draw(window);
    
    ScreenManager::getInstance().drawScreen(*WindowManager::getInstance().getWindow());
    
    window.display();
  }

  return 0;
}