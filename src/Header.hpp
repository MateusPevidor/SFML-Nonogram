#ifndef HEADER_HPP
#define HEADER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Header {
  private:

  public:
    sf::Text text;
    Header();
    Header(int value, sf::Vector2f position, float cellSize);
    void draw(sf::RenderWindow &window);
};

#endif