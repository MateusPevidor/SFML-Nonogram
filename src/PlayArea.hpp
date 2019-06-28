#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Cell.hpp"
#include "Line.hpp"
#include "Header.hpp"
#include "LevelManager.hpp"

typedef struct { // Struct para auxílio ao lidar com cliques na tela
  sf::Vector2f position; // Posição do primeiro quadrado
  sf::Vector2f dimensions; // Contagem de quadrados horizontais e verticais
  sf::Vector2f limits; // Coordenadas do limite da PlayArea
  int cellSize;
} PlayAreaProperties;

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
    void importHeaders(float cellSize, int guideSize, int offsetX, int offsetY); // Transforma os números guardados no Level em texto para renderização
    PlayAreaProperties properties;
  
  public:
    PlayArea();
    PlayArea(int rows, int cols, int guideSize);
    PlayAreaProperties getProperties();
    void changeCellState(int i, int j, int state);
    std::vector <std::vector <Cell>> getCells();
    std::vector <std::vector <Header>> getColHeaders();
    std::vector <std::vector <Header>> getRowHeaders();
    void updateHeaders(int i, int j);
    void draw(sf::RenderWindow &window);
    
};

#endif