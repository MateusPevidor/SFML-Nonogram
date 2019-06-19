#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Cell.hpp"
#include "Line.hpp"
#include "Header.hpp"
#include "LevelManager.hpp"

class PlayArea {
  private:
    sf::RectangleShape background; // Fundo
    sf::Vector2f position; // Posição
    sf::Vector2f dimensions; // Tamanho
    std::vector <Line> borders; // Bordas
    std::vector <std::vector <Header>> colHeaders; // Cabeçalhos
    std::vector <std::vector <Header>> rowHeaders; // Cabeçalhos
    std::vector <std::vector <Cell>> cells; // Quadrados
    std::vector <Line> guideLines; // Linhas
  
  public:
    PlayArea();
    PlayArea(int rows, int cols, int guideSize);
    void importHeaders(float cellSize, int guideSize);
    void draw(sf::RenderWindow &window);
};

#endif