#ifndef PLAY_SCREEN_HPP
#define PLAY_SCREEN_HPP

#include <vector>
#include "Screen.hpp"
#include "PlayArea.hpp"
#include "GameManager.hpp"
#include "WindowManager.hpp"
#include "Line.hpp"
#include "ButtonClose.hpp"
#include "ButtonPause.hpp"
#include "ButtonHint.hpp"
#include "ButtonSave.hpp"
#include "ButtonLoad.hpp"

class PlayScreen : public Screen {
  private:
    PlayArea playArea;
    
    sf::RectangleShape backgroundShape;
    std::vector <Line> backgroundLines;

    ButtonClose *buttonClose;
    ButtonPause *buttonPause;
    ButtonHint *buttonHint;
    ButtonSave *buttonSave;

  public:
    PlayScreen();
    PlayArea getPlayArea();
    PlayArea* getPlayAreaAddress();
    void setPlayArea(PlayArea playArea);
    void handleClick(sf::Event);
    void draw(sf::RenderWindow &window);
};

#endif