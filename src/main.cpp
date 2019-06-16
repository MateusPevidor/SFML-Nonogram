#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameManager.hpp"
#include "LevelManager.hpp"
#include "TextureManager.hpp"


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "UltimatePix");
  window.setVerticalSyncEnabled(1);

  LevelManager::getInstance().loadCustomLevel("level1");
  
  GameManager::getInstance().generatePlayArea("level1");
  

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    
    GameManager::getInstance().getPlayArea().draw(window);
    
    window.display();
  }

  return 0;
}
