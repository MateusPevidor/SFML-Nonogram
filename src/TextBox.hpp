#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <SFML/Graphics.hpp>
#include "FontManager.hpp"
#include "Line.hpp"

class TextBox {
  private:
    sf::Text text;
    sf::Text headerText;
    sf::Text loadButtonText;
    sf::Text saveButtonText;
    sf::RectangleShape backgroundShape;
    std::vector <Line> backgroundLines;
  public:
    TextBox();
    sf::Text* getText();
    void setupText();
    void draw(sf::RenderWindow &window);
};

#endif