#ifndef HEADER_HPP
#define HEADER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Header {
  private:
    sf::Text text;

  public:
    Header();
    Header(int value);
    void draw(sf::RenderWindow &window);
};

#endif