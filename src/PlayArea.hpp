#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Cell.hpp"
#include "GuideLine.hpp"

class PlayArea {
  private:
    sf::Sprite backgroundSprite; // Imagem de fundo
    sf::Vector2f position; // Posição
  
  public:
    PlayArea();
    PlayArea(int rows, int cols, int guideSize);
    std::vector <std::vector <Cell>> cells; // Quadrados
    std::vector <GuideLine> guideLines; // Linhas
    void draw(sf::RenderWindow &window);
};

#endif