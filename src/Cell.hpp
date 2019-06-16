#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

class Cell {
  private:
    sf::RectangleShape shape; // Quadrado cinza claro (preenchido)
    sf::Vector2f position; // Posições X e Y
    sf::Vector2f dimensions; // Largura e altura
    sf::Sprite crossSprite; // Sprite do X
    int state; // 0. Vazio - 1. Preenchido - 2. Marcado com X
  
  public:
    Cell(int x, int y, int w, int h);
    void draw(sf::RenderWindow &window);
    int getState();
    void setState(int state);
};

#endif