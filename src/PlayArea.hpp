#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Cell.hpp"
#include "Line.hpp"

class PlayArea {
  private:
    sf::RectangleShape background;
    std::vector <Line> borders;
    sf::Vector2f position; // Posição
  
  public:
    PlayArea();
    PlayArea(int rows, int cols, int guideSize);
    std::vector <std::vector <Cell>> cells; // Quadrados
    std::vector <Line> guideLines; // Linhas
    void draw(sf::RenderWindow &window);
};

#endif