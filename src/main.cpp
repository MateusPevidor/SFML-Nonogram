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

int main(int argc, char* argv[]) {
  sf::RenderWindow window(
    sf::VideoMode(800, 800),
    "UltimatePix",
    sf::Style::Titlebar | sf::Style::Close
  );
  window.setVerticalSyncEnabled(1);

  FontManager::getInstance().addFont("../assets/fonts/Square.ttf");
  LevelManager::getInstance().loadCustomLevel("level3");
  
  GameManager::getInstance().generatePlayArea("level3");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed)
        std::cout << event.mouseButton.button << std::endl;
    }

    window.clear();
    
    GameManager::getInstance().getPlayArea().draw(window);
    
    window.display();
  }

  return 0;
}