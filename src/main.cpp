#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "PlayArea.hpp"
#include "TextureManager.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "UltimatePix");
  window.setVerticalSyncEnabled(1);

  PlayArea playArea(5, 5, 2);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    playArea.draw(window);

    window.display();
  }

  return 0;
}
