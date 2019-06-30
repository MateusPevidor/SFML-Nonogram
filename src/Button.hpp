#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

class Button {
  private:
    sf::Vector2f position;
    sf::Sprite sprite;

  public:
    Button();
    Button(int x, int y);
    void draw(sf::RenderWindow &window);

};

#endif