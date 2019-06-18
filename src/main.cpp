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
  LevelManager::getInstance().loadCustomLevel("level1");
  
  GameManager::getInstance().generatePlayArea("level1");


  Header asd(2);

  sf::Font font = FontManager::getInstance().getFont("../assets/fonts/Square.ttf");
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(70);
  text.setFillColor(sf::Color(163, 163, 163));
  text.setString("asd");


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    
    GameManager::getInstance().getPlayArea().draw(window);
    asd.draw(window);
    // window.draw(text);
    
    window.display();
  }

  return 0;
}
