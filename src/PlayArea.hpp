#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Quadrado.hpp"
#include "GuideLine.hpp"

class PlayArea {
  private:
    sf::Sprite backgroundSprite; // Imagem de fundo
    sf::Vector2f position; // Posição
  
  public:
    PlayArea();
    PlayArea(int rows, int cols, int guideSize);
    std::vector <std::vector <Quadrado>> quadrados;
    std::vector <GuideLine> guideLines;
    void draw(sf::RenderWindow &window);
};

#endif