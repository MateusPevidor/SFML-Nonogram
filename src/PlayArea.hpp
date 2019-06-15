#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Quadrado.hpp"

class PlayArea {
  private:
    sf::Sprite backgroundSprite; // Imagem de fundo
    sf::Vector2f position; // Posição
  
  public:
    PlayArea(int lines, int cols, int guideSize);
    std::vector <std::vector <Quadrado>> quadrados;
    void draw(sf::RenderWindow &window);
};

#endif