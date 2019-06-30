#ifndef BOARD_PREVIEW_HPP
#define BOARD_PREVIEW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.hpp"

class BoardPreview {
  private:
    std::vector <std::vector <Cell>> cells;
  public:
    BoardPreview(int rows, int cols, sf::Vector2f position, sf::Vector2f dimensions);
    std::vector <std::vector <Cell>> getCells();
    void updateCell(int i, int j, int state);
    void draw(sf::RenderWindow &window);
};

#endif