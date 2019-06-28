#ifndef PLAY_SCREEN_HPP
#define PLAY_SCREEN_HPP

#include <vector>
#include "Screen.hpp"
#include "PlayArea.hpp"
#include "GameManager.hpp"
#include "Line.hpp"

class PlayScreen : public Screen {
  private:
    PlayArea playArea;
    
    sf::RectangleShape backgroundShape;
    std::vector <Line> backgroundLines;
    
  public:
    PlayScreen();
    PlayArea getPlayArea();
    void setPlayArea(PlayArea playArea);
    void handleClick(sf::Event);
    void draw(sf::RenderWindow &window);
};

#endif