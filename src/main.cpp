#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "FontManager.hpp"
#include "GameManager.hpp"
#include "LevelManager.hpp"
#include "TextureManager.hpp"

#include "Header.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "UltimatePix");
  window.setVerticalSyncEnabled(1);

  FontManager::getInstance().addFont("../assets/fonts/Square.ttf");
  LevelManager::getInstance().loadCustomLevel("level2");
  
  GameManager::getInstance().generatePlayArea("level2");


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

/*
#!/bin/bash/

g++ -c *.cpp -I ../dependencies/include
g++ *.o -o sfml-app -L ../dependencies/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=../dependencies/lib
./sfml-app

 */