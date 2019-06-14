#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Quadrado.hpp"

class PlayArea {
  private:
    sf::Sprite backgroundSprite;
    sf::Vector2f position;
  
  public:
    std::vector <std::vector <Quadrado>> quadrados;
    PlayArea(int lines, int cols, int guideSize);
    void draw(sf::RenderWindow &window);
};

#endif