#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Line { // Linhas que dividem o tabuleiro
  private:
    sf::Vector2f position;
    sf::Vector2f dimensions;
    sf::RectangleShape shape;

  public:
    Line(int x, int y, int w, int h);
    void setColor(int r, int g, int b);
    void draw(sf::RenderWindow &window);
};

#endif