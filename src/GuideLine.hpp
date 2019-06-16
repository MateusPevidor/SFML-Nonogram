#ifndef GUIDE_LINE_HPP
#define GUIDE_LINE_HPP

#include <SFML/Graphics.hpp>

class GuideLine { // Linhas que dividem o tabuleiro
  private:
    sf::Vector2f position;
    sf::Vector2f dimensions;
    sf::RectangleShape shape;

  public:
    GuideLine(int x, int y, int w, int h);
    void draw(sf::RenderWindow &window);
};

#endif