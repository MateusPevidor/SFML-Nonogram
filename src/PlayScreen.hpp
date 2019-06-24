#ifndef PLAY_SCREEN_HPP
#define PLAY_SCREEN_HPP

#include "Screen.hpp"
#include "PlayArea.hpp"

class PlayScreen : public Screen {
  private:
    PlayArea playArea;
    
  public:
    PlayArea getPlayArea();
    void setPlayArea(PlayArea playArea);
    void handleClick(sf::Event);
    void draw(sf::RenderWindow &window);
};

#endif