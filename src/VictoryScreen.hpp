#ifndef VICTORY_SCREEN_HPP
#define VICTORY_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "Line.hpp"
#include "FontManager.hpp"

class VictoryScreen : public Screen {
  private:
    sf::RectangleShape backgroundShape;
    std::vector <Line> backgroundLines;
    sf::Text message;
  public:
    VictoryScreen();
    void draw(sf::RenderWindow &window);
};

#endif