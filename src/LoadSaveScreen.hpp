#ifndef LOAD_SAVE_SCREEN_HPP
#define LOAD_SAVE_SCREEN_HPP

#include <vector>
#include "Screen.hpp"
#include "GameManager.hpp"
#include "WindowManager.hpp"
#include "Line.hpp"
#include "ButtonClose.hpp"
#include "ButtonSave.hpp"
#include "ButtonLoad.hpp"
#include "TextBox.hpp"

class LoadSaveScreen : public Screen {
  private:
    
    sf::RectangleShape backgroundShape;
    std::vector <Line> backgroundLines;
    TextBox textBox;
    ButtonClose *buttonClose;
    ButtonSave *buttonSave;
    ButtonLoad *buttonLoad;

  public:
    LoadSaveScreen();
    void handleClick(sf::Event);
    void handleText(sf::Event);
    void draw(sf::RenderWindow &window);
};

#endif